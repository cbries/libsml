#pragma once

#include <curl/curl.h>
#include <iostream>
#include <string>

#include "base64.hpp"

using namespace std;

int DoJsonUpload(std::string json)
{
	std::string url = "https://www.christianbenjaminries.de/raspberry/stromzaehler/handle.php";

        std::string decodedData = base64_encode(json);
        std::string request = url + std::string("?data=") + decodedData;
        CURL *curl;
  	CURLcode res;
	curl = curl_easy_init();
	if(curl) {
    		curl_easy_setopt(curl, CURLOPT_URL, request.c_str());

    		/* Perform the request, res will get the return code */
    		res = curl_easy_perform(curl);
    		/* Check for errors */
    		if(res != CURLE_OK)
      			fprintf(stderr, "curl_easy_perform() failed: %s\n",
              		curl_easy_strerror(res));

	   	/* always cleanup */
		curl_easy_cleanup(curl);
        }

	printf("\nUpload done.\n");

        return 0;
}

