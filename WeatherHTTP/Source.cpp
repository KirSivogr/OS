#include <string>
#include <iostream>
#include <fstream>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>

using namespace Poco::Net;
using namespace std;
using namespace Poco;

int main() {
    // create session
    URI uri("http://api.weather.yandex.ru/v2/forecast?lat=53.893869&lon=27.547153");
    HTTPClientSession session(uri.getHost(), uri.getPort());

    session.setKeepAlive(true);

    string path(uri.getPathAndQuery());
    if (path.empty()) {
        path = "/";
    }

    HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
    request.add("X-Yandex-API-Key", "132aa006-8d6a-45ac-86df-eb39cb0b2d76");
    session.sendRequest(request);
    HTTPResponse response;
    istream& fin = session.receiveResponse(response);
    cout << response.getStatus() << endl;

    ofstream fout("report.json");
    StreamCopier::copyStream(fin, fout);
}