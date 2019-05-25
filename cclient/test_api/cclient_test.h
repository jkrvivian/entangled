#include "cclient/api/core/core_api.h"
#include "cclient/api/extended/extended_api.h"
#include "cclient/http/http.h"
#include "cclient/service.h"
#include "common/model/transaction.h"
#include "utils/containers/hash/hash8019_queue.h"

#define SEED                                                                   \
  "AMRWQP9BUMJALJHBXUCHOD9HFFD9LGTGEAWMJWWXSDVOF9PI9YGJAPBQLQUOMNYEQCZPGCTHGV" \
  "NNAPGHA"
#define RAWTXN                                                                 \
  "NEH99999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "99999999999999999999999999999999999999999NVFBXNPZGQUTTNN9VMSWXOYWVIOJIDUQ9" \
  "JU9ORKDSSVSLCYTUHWPWIL9XJGP9FQCWETJUNLDBOEFTFLTK99999999999999999999999999" \
  "9BSAIFUSYVCEK999999999999999SFBSGZD99999999999999999999WMUHDKRBETLPVY9GYCL" \
  "XAGITTRPKZLQFSBHPOJCGEPBLHW9BBH99FOLPRPZPVEISLF9IXRIYKZKZFW9QWIBBCX9PKDFHZ" \
  "LFALMNFKOIMVOSOUHLDVEFKXPUEQWFMZJNLUUCPSYGRMTQPOF9ALCGFHDYSJYUEHA9999MPQH9" \
  "ACUKGCYWTHGCIYVWFGDEUM9KEGHPFLM9FXS9ZUUXEBOORQAUJOWBWLPPSPHYSHTKFFGUROF999" \
  "99VQAIFUSYVCEK999999999999999ZHZTKDCLE999999999MMMMMMMMMRFJCYJLMPSQBS9GFEA" \
  "LACBKEWQR"