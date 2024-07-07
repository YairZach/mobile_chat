project(github.com/YairZach/mobile_chat)


set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-std=c++23")

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

set(SOURCE_FILES 
  main.cpp
  communicator.cpp
  loggedUser.cpp
  loginManager.cpp
  loginRequestHandler.cpp
  requestHandlerFactory.cpp
  server.cpp
  jsonSerializer.cpp
  jsonDeserializer.cpp
  sqlite3..c
  sqliteDatabase.cpp
  )

add_executable(main main.cpp ${SOURCE_FILES})

target_link_libraries(main 
  PRIVATE 
  nlohmann_json::nlohmann_json
  fmt::fmt)
