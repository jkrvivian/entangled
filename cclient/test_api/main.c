#include <stdio.h>

#include "cclient/http/http.h"
#include "cclient/iota_api.h"
#include "cclient/serialization/json/json_serializer.h"

int main() {
  serializer_t serializer;
  iota_api_result_t result;
  init_json_serializer(&serializer);
  get_node_info_res_t* res = get_node_info_res_new();
  iota_http_service_t service = {
      .host = "node10.puyuma.org",
      .port = 14266,
      .content_type = "application/json",
      .version = 1,
      .serializer = serializer,
  };
  result = iota_api_get_node_info(&service, &res);
  printf("appname: %s\n", res->app_name->data);
  printf("app_version: %s\n", res->app_version->data);
  printf("jre_available_processors: %d\n", res->jre_available_processors);
  printf("neighbors: %d\n", res->neighbors);
  printf("tips: %d\n", res->tips);
  printf("latest_milestone: %s\n", res->latest_milestone->trits);

  return 0;
}
