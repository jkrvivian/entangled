#include <stdio.h>

#include "cclient/http/http.h"
#include "cclient/iota_api.h"
#include "cclient/serialization/json/json_serializer.h"
#include "cclient_test.h"

void test_get_node_info(iota_http_service_t* service) {
  printf("***************** test_get_node_info *************\n");
  iota_api_result_t result;
  get_node_info_res_t* res = get_node_info_res_new();

  result = iota_api_get_node_info(service, &res);
  printf("appname: %s\n", res->app_name->data);
  printf("app_version: %s\n", res->app_version->data);
  printf("jre_available_processors: %d\n", res->jre_available_processors);
  printf("neighbors: %d\n", res->neighbors);
  printf("tips: %d\n", res->tips);
  printf("latest_milestone: %s\n", res->latest_milestone->trits);

  get_node_info_res_free(&res);
  printf("************** test_get_node_info_end ************\n\n");
}

void test_get_txn_to_approve(iota_http_service_t* service,
                             attach_to_tangle_res_t** res) {
  printf("************* test_get_txn_to_approve ************\n");
  iota_api_result_t result;
  get_transactions_to_approve_req_t* req =
      get_transactions_to_approve_req_new();
  req->depth = 15;

  result = iota_api_get_transactions_to_approve(service, req, res);
  get_transactions_to_approve_req_free(&req);
  printf("********* test_get_txn_to_approve_end ************\n\n");
}

void test_attach_to_tangle(iota_http_service_t* service) {
  printf("************* test_attach_to_tangle **************\n");
  int i = 0;
  iota_api_result_t result;
  attach_to_tangle_req_t* req = attach_to_tangle_req_new();
  attach_to_tangle_res_t* res = attach_to_tangle_res_new();
  get_transactions_to_approve_res_t* res_tb =
      get_transactions_to_approve_res_new();

  test_get_txn_to_approve(service, &res_tb);

  req->trunk = res_tb->trunk;
  req->branch = res_tb->branch;
  attach_to_tangle_req_set_mwm(req, 18);
  req->trytes = attach_to_tangle_req_add_trytes(req->trytes, RAWTXN);

  result = iota_api_attach_to_tangle(service, req, &res);
  if (result.error == RC_OK) {
    for (i = 0; i < attach_to_tangle_res_trytes_cnt(res); i++) {
      char_buffer_t* t = char_buffer_new();
      flex_hash_to_char_buffer(get_trytes_res_at(res, i), t);
      printf("%s\n", t->data);
      char_buffer_free(t);
    }
  }
  get_transactions_to_approve_res_free(&res);
  attach_to_tangle_res_free(res);
  attach_to_tangle_req_free(&req);
  printf("*********** test_attach_to_tangle_end ***********\n\n");
}

int main() {
  serializer_t serializer;
  init_json_serializer(&serializer);
  iota_http_service_t service = {
      .host = "node10.puyuma.org",
      .port = 14266,
      .content_type = "application/json",
      .version = 1,
      .serializer = serializer,
  };
  test_get_node_info(&service);
  test_attach_to_tangle(&service);
  return 0;

}
