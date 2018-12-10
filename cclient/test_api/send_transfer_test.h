#include <string.h>
#include <time.h>

#include "cclient/http/http.h"
#include "cclient/iota_client_core_api.h"
#include "cclient/iota_client_extended_api.h"
#include "cclient/service.h"
#include "common/model/bundle.h"
#include "common/model/transaction.h"
#include "utils/containers/hash/hash8019_queue.h"

#define SEED                                                                   \
  "AMRWQP9BUMJALJHBXUCHOD9HFFD9LGTGEAWMJWWXSDVOF9PI9YGJAPBQLQUOMNYEQCZPGCTHGV" \
  "NNAPGHA"
#define TAG_MSG "TANGLEACCELERATORTEST"
