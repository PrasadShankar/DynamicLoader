
 #include "TestSpeed.h"
 #include <string.h>

 using namespace std;


 CurlPlugin::CurlPlugin()
 {
 
  m_curl = curl_easy_init(); 
  strcpy(outfilename, "file1");  

 }
 
 bool CurlPlugin::run()
 {
  CURLcode res = CURLE_OK; 
  char *url ="http://speedtest.wdc01.softlayer.com/downloads/test100.zip";
  if (m_curl)
    {   
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(m_curl, CURLOPT_URL, url);
        curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, fp);
//        curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(m_curl);
        if ( res != CURLE_OK) 
           cout << " Download Error "<<endl;

        curl_easy_cleanup(m_curl);
        fclose(fp);
    }   
 
 }

 int CurlPlugin::get_progress()
 {
        // Get the download progress using Curl Callback

 }

 std::string CurlPlugin::get_status_msg()
 {
       // Get the status and print the message;
      cout<<"SUCCESS"<<endl;

 }
  
 extern "C" CurlPlugin* create()
 {
    return new CurlPlugin();
 }
 extern "C" void destroy(CurlPlugin* cl)
 {
    delete cl ;
 }


 
