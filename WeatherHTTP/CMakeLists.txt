cmake_minimum_required(VERSION 3.22) 
 
project(WeatherHTTP)  
 
find_package(Poco REQUIRED Net Foundation)  
 
add_executable(WeatherHTTP poco_request.cpp) 
 
target_link_libraries(WeatherHTTP PUBLIC 
  Poco::Net 
) 
 
 
set_target_properties( 
       WeatherHTTP PROPERTIES 
       CXX_STANDARD 17 
       CXX_STANDARD_REQUIRED ON 
)
