#include "httpClient.h"

HttpClient::HttpClient(){

};

String HttpClient::GET(String url)
{
    client.begin(url);

    int code = client.GET();

    if (code != 200)
    {
        return "";
    };

    return client.getString();
};
String HttpClient::POST(String url, String body, int expectedCode)
{
    client.begin(url);

    int code = client.POST(body);

    if(code != expectedCode){
        return "";
    };

    return client.getString();

};