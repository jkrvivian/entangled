#include <stdio.h>

#include "cclient_test.h"

void test_get_node_info(iota_client_service_t* service) {
  printf("***************** test_get_node_info *************\n");
  retcode_t result = RC_OK;
  get_node_info_res_t* res = get_node_info_res_new();

  result = iota_client_get_node_info(service, res);
  printf("appname: %s\n", res->app_name->data);
  printf("app_version: %s\n", res->app_version->data);
  printf("jre_available_processors: %d\n", res->jre_available_processors);
  printf("neighbors: %d\n", res->neighbors);
  printf("tips: %d\n", res->tips);

  printf("latest_milestone: ");
  // flex to trytes;
  size_t len_trytes = 243 / 3;
  trit_t trytes_out[len_trytes + 1];
  size_t trits_count = flex_trits_to_trytes(trytes_out, len_trytes,
                                            res->latest_milestone, 243, 243);
  trytes_out[len_trytes] = '\0';
  if (trits_count != 0) {
    printf("%s\n", trytes_out);
  }

  get_node_info_res_free(&res);
  printf("************** test_get_node_info_end ************\n\n");
}

void test_get_txn_to_approve(iota_client_service_t* service,
                             get_transactions_to_approve_res_t* res) {
  printf("************* test_get_txn_to_approve ************\n");
  retcode_t result = RC_OK;
  get_transactions_to_approve_req_t* req =
      get_transactions_to_approve_req_new();
  req->depth = 15;

  result = iota_client_get_transactions_to_approve(service, req, res);
  get_transactions_to_approve_req_free(&req);
  printf("********* test_get_txn_to_approve_end ************\n\n");
}

void test_attach_to_tangle(iota_client_service_t* service) {
  printf("************* test_attach_to_tangle **************\n");
  retcode_t result = RC_OK;
  flex_trit_t trits_8019[8019];
  attach_to_tangle_req_t* req = attach_to_tangle_req_new();
  attach_to_tangle_res_t* res = attach_to_tangle_res_new();
  get_transactions_to_approve_res_t* res_tb =
      get_transactions_to_approve_res_new();

  test_get_txn_to_approve(service, res_tb);

  memcpy(req->trunk, res_tb->trunk, sizeof(req->trunk));
  memcpy(req->branch, res_tb->branch, sizeof(req->branch));
  flex_trits_from_trytes(trits_8019, 8019, (const tryte_t*)RAWTXN, 2673, 2673);
  hash8019_queue_push(&req->trytes, trits_8019);
  req->mwm = 18;

  result = iota_client_attach_to_tangle(service, req, res);
  if (result == RC_OK) {
    flex_trit_t* ary = hash8019_queue_peek(res->trytes);
    // flex to trytes;
    size_t len_trytes = 8019 / 3;
    trit_t trytes_out[len_trytes + 1];
    size_t trits_count =
        flex_trits_to_trytes(trytes_out, len_trytes, ary, 8019, 8019);
    trytes_out[len_trytes] = '\0';
    if (trits_count != 0) {
      printf("%s\n", trytes_out);
    }
  }

  get_transactions_to_approve_res_free(&res_tb);
  attach_to_tangle_res_free(&res);
  attach_to_tangle_req_free(&req);
  printf("*********** test_attach_to_tangle_end ***********\n\n");
}

void test_get_new_address(iota_client_service_t* service) {
  printf("************* test_get_new_address **************\n");
  retcode_t result = RC_OK;
  hash243_queue_t out = NULL;
  flex_trit_t seed[243];
  flex_trits_from_trytes(seed, 243, (const tryte_t*)SEED, 81, 81);
  address_opt_t opt = {.security = 3, .start = 0, .total = 0};

  result = iota_client_get_new_address(service, seed, opt, &out);

  if (result == RC_OK) {
    flex_trit_t* ary = hash243_queue_peek(out);
    // flex to trytes;
    size_t len_trytes = 243 / 3;
    trit_t trytes_out[len_trytes + 1];
    size_t trits_count =
        flex_trits_to_trytes(trytes_out, len_trytes, ary, 243, 243);
    trytes_out[len_trytes] = '\0';
    if (trits_count != 0) {
      printf("generate address:\n%s\n\n", trytes_out);
    }
  }
  hash243_queue_free(&out);
  printf("************* test_get_new_address_end ***********\n\n");
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
  test_get_node_info(&service);
  test_attach_to_tangle(&service);
  test_get_new_address(&service);

  iota_client_core_destroy(&service);
  return 0;
}
