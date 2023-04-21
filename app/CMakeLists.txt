project(app)



add_executable(client client.cpp)


get_property(INCLUDE_DIR GLOBAL PROPERTY "INCLUDE_DIR")

target_include_directories(client PUBLIC ${INCLUDE_DIR})


