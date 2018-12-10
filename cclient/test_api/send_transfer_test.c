#include "send_transfer_test.h"

int send_transfer_test(iota_client_service_t* service) {
  iota_transaction_t curr_tx = NULL;
  char trytes_out[82];
  retcode_t result = RC_OK;
  iota_transaction_t tx = transaction_new();
  bundle_transactions_t* bundle;
  bundle_transactions_new(&bundle);
  flex_trit_t bundle_hash[243];

  /* init generate address */
  hash243_queue_t out = NULL;
  flex_trit_t seed[243];
  flex_trits_from_trytes(seed, 243, (const tryte_t*)SEED, 81, 81);
  address_opt_t opt = {.security = 3, .start = 0, .total = 0};

  /* init GTTA */
  get_transactions_to_approve_res_t* res =
      get_transactions_to_approve_res_new();
  get_transactions_to_approve_req_t* req =
      get_transactions_to_approve_req_new();
  req->depth = 15;

  /* tag and message */
  int tag_msg_len = strlen(TAG_MSG);
  flex_trit_t tag_msg_trits[tag_msg_len * 3];
  flex_trits_from_trytes(tag_msg_trits, tag_msg_len * 3,
                         (const tryte_t*)TAG_MSG, tag_msg_len, tag_msg_len);

  /* get new address */
  result = iota_client_get_new_address(service, seed, opt, &out);
  if (result == RC_OK) {
    transaction_set_address(tx, hash243_queue_peek(out));
  }

  transaction_set_tag(tx, tag_msg_trits);
  transaction_set_message(tx, tag_msg_trits);
  transaction_set_value(tx, 0);
  bundle_transactions_add(bundle, tx);
  calculate_bundle_hash(bundle, bundle_hash);

  /* print bundle hash */
  flex_trits_to_trytes((tryte_t*)trytes_out, 81, bundle_hash, 243, 243);
  trytes_out[81] = '\0';
  printf("bundle hash:%s\n", trytes_out);

  /* fill in bundle hash through each tx */
  for (curr_tx = (iota_transaction_t)utarray_front(bundle); curr_tx != NULL;
       curr_tx = (iota_transaction_t)utarray_next(bundle, curr_tx)) {
    transaction_set_bundle(curr_tx, bundle_hash);
  }
  /* TODO(jkrvivian): sign bundle */

  /* GTTA */
  result = iota_client_get_transactions_to_approve(service, req, res);
  flex_trits_to_trytes((tryte_t*)trytes_out, 81, res->trunk, 243, 243);
  trytes_out[81] = '\0';
  printf("trunk:%s\n", trytes_out);
  flex_trits_to_trytes((tryte_t*)trytes_out, 81, res->branch, 243, 243);
  trytes_out[81] = '\0';
  printf("branch:%s\n", trytes_out);

  struct timeval tv;
  /* fill in timestamp, trunk, branch, nonce */
  for (curr_tx = (iota_transaction_t)utarray_front(bundle); curr_tx != NULL;
       curr_tx = (iota_transaction_t)utarray_next(bundle, curr_tx)) {
    transaction_set_trunk(curr_tx, res->trunk);
    transaction_set_branch(curr_tx, res->branch);
    gettimeofday(&tv, NULL);
    transaction_set_timestamp(curr_tx, (uint64_t)tv.tv_sec * 1000);
    /* PoW */
  }

  /* hash queue from generate address */
  hash243_queue_free(&out);
  get_transactions_to_approve_req_free(&req);
  get_transactions_to_approve_res_free(&res);
}

int main() {
  http_info_t http = {
      .host = "node10.puyuma.org",
      .port = 14266,
      .api_version = 1,
  };

  iota_client_service_t service = {
      .http = http,
      .serializer_type = SR_JSON,
  };
  iota_client_core_init(&service);

  send_transfer_test(&service);

  iota_client_core_destroy(&service);
  return 0;
}
