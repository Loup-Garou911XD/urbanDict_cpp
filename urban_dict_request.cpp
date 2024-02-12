#include "urban_dict_request.h"
#include <stdio.h>
#include <iostream>
#include <curl/curl.h>

// Callback function to handle received data (suppressing output)
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    // Simply return the size of the received data to suppress output
    
    char *data = reinterpret_cast<char*>(contents); //casting to char because here we assume the data is text
    std::cout<<data;
    return size * nmemb;
}

int UrbanDictionaryRequest(const std::string &term) {
    CURL* curl;
    CURLcode result;

    const std::string url = "https://urban-dictionary7.p.rapidapi.com/v0/define?term=";
    std::string final_url = url + term;

    curl = curl_easy_init();
    if (curl == NULL) {
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, final_url.c_str());

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "X-RapidAPI-Key: 121a86bd3fmshe1216adc6c58d55p10e1b2jsn54564f6b0072");
    headers = curl_slist_append(headers, "X-RapidAPI-Host: urban-dictionary7.p.rapidapi.com");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Set a custom write callback to suppress output
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    result = curl_easy_perform(curl);
    
    if (result != CURLE_OK) {
        return -1;
    }

    return 0;
}
