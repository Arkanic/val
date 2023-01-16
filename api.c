#include <json-c/json_object.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>

#include "val.h"

CURL *curl;
struct string s;

void api_init(void) {
    curl = curl_easy_init();
}

void api_shutdown(void) {
    curl_easy_cleanup(curl);
}

float api_totalvalue(char *wallets[], int walletcount) {
    char *baseurl = "blockchain.info/multiaddr?active=";
    int len = strlen(baseurl);
    len += 63 * walletcount; // extra is for pipe, 62 is for segwit address (longest)

    char *url = malloc((sizeof(char) * len) + 1);
    strcpy(url, baseurl);
    for(int i = 0; i < walletcount; i++) {
        strcat(url, wallets[i]);
        strcat(url, "|");
    }

    webget(curl, &s, url);

    struct json_object *response = json_tokener_parse(s.ptr);
    struct json_object *responseWallet = json_object_object_get(response, "wallet");
    struct json_object *responseFinalBalance = json_object_object_get(responseWallet, "final_balance");
    unsigned long long finalBalance = json_object_get_int64(responseFinalBalance);

    printf("%llu\n", finalBalance);

    json_object_put(response);
    free(s.ptr);

    return 0.0;
}