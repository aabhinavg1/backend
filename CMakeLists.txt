﻿cmake_minimum_required(VERSION 3.20)

set(project_name my-project) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 23)


if (MSVC)
    add_compile_options(/wd4291)
endif()


add_library(${project_name}-lib
        src/AppComponent.hpp
        src/controller/MyController.cpp
        src/controller/MyController.hpp
         "src/data/personal information/CitizenIdentifyCard.h" "src/data/personal information/CitizenIdentifyCard.cpp" "include/tool.cpp"    "src/type/Date.h" "src/type/Date.cpp"   "include/initialisation.h" "include/initialisation.cpp" "src/entity/account/Account.h" "src/entity/account/Account.cpp" "src/entity/client/Client.h" "src/entity/client/Client.cpp" "src/entity/transaction/Transaction.h" "src/entity/account/BasicAccount.h" "src/entity/account/BasicAccount.cpp" "src/entity/transaction/Transaction.cpp"   "src/service/client/ClientService.h"  "src/service/client/ClientService.cpp" "src/service/account/AccountService.h" "src/repository/client/ClientRepository.h" "src/repository/client/ClientRepository.cpp"  "src/repository/account/AccountRepository.h" "src/repository/account/AccountRepository.cpp" "src/service/account/AccountService.cpp" "src/repository/citizen identify card/CitizenIdentifyCardRepository.h" "src/repository/citizen identify card/CitizenIdentifyCardRepository.cpp" "src/service/citizen identify card/CitizenIdentifyCardService.h" "src/service/citizen identify card/CitizenIdentifyCardService.cpp" "include/OracleQuery.h" "include/tool.h" "src/controller/citizen identify card/CitizenIdentifyCardController.h"  "src/dto/citizen identify card/CitizenIdentifyCardDTO.h" "src/repository/transaction/TransactionRepository.h" "src/repository/transaction/TransactionRepository.cpp" "src/service/transaction/TransactionService.h" "src/service/transaction/TransactionService.cpp" "src/exception/oracle/CustomOracleException.h" "src/exception/oracle/CustomOracleException.cpp" "src/dto/ResponseDTO.hpp" "src/controller/account/AccountController.h" "src/controller/client/ClientController.h" "src/dto/client/ClientRequest.h" "src/dto/client/ClientResponse.h" "include/define.h"  "src/dto/DTOs.hpp")

## link libs

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories($ENV{ORACLE_HOME}/oci/include)

find_package(oatpp 1.4.0 REQUIRED)
find_package(Boost 1.70.0 REQUIRED system filesystem locale)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        $ENV{ORACLE_HOME}/oci/lib/msvc/oraocci21d.lib
        PRIVATE Boost::headers Boost::system Boost::filesystem Boost::locale
)

target_include_directories(${project_name}-lib PUBLIC src ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
## add executables

add_executable(${project_name}-exe
        src/App.cpp
        test/app/MyApiTestClient.hpp  "src/data/personal information/CitizenIdentifyCard.h" "src/data/personal information/CitizenIdentifyCard.cpp" "include/tool.cpp"    "src/type/Date.h" "src/type/Date.cpp"   "include/initialisation.h" "include/initialisation.cpp" "src/entity/account/Account.h" "src/entity/account/Account.cpp"  "src/entity/client/Client.h" "src/entity/client/Client.cpp" "src/entity/transaction/Transaction.h" "src/entity/account/BasicAccount.h" "src/entity/account/BasicAccount.cpp" "src/entity/transaction/Transaction.cpp"   "src/service/client/ClientService.h"  "src/service/client/ClientService.cpp" "src/service/account/AccountService.h" "src/repository/client/ClientRepository.h" "src/repository/client/ClientRepository.cpp"  "src/repository/account/AccountRepository.h" "src/repository/account/AccountRepository.cpp" "src/service/account/AccountService.cpp" "src/repository/citizen identify card/CitizenIdentifyCardRepository.h" "src/repository/citizen identify card/CitizenIdentifyCardRepository.cpp" "src/service/citizen identify card/CitizenIdentifyCardService.h" "src/service/citizen identify card/CitizenIdentifyCardService.cpp" "include/OracleQuery.h" "include/tool.h" "src/controller/citizen identify card/CitizenIdentifyCardController.h"  "src/dto/citizen identify card/CitizenIdentifyCardDTO.h" "src/repository/transaction/TransactionRepository.h" "src/repository/transaction/TransactionRepository.cpp" "src/service/transaction/TransactionService.h" "src/service/transaction/TransactionService.cpp" "src/exception/oracle/CustomOracleException.h" "src/exception/oracle/CustomOracleException.cpp" "src/dto/ResponseDTO.hpp" "src/controller/account/AccountController.h" "src/controller/client/ClientController.h" "src/dto/client/ClientRequest.h" "src/dto/client/ClientResponse.h" "include/define.h"  "src/dto/DTOs.hpp")
target_link_libraries(${project_name}-exe ${project_name}-lib)
target_link_libraries(${project_name}-exe )

add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
        test/tests.cpp
        test/app/TestComponent.hpp
        test/app/MyApiTestClient.hpp
        test/MyControllerTest.cpp
        test/MyControllerTest.hpp
   "src/data/personal information/CitizenIdentifyCard.h" "src/data/personal information/CitizenIdentifyCard.cpp" "include/tool.cpp"    "src/type/Date.h" "src/type/Date.cpp"   "include/initialisation.h" "include/initialisation.cpp" "src/entity/account/Account.h" "src/entity/account/Account.cpp"  "src/entity/client/Client.h" "src/entity/client/Client.cpp" "src/entity/transaction/Transaction.h" "src/entity/account/BasicAccount.h" "src/entity/account/BasicAccount.cpp" "src/entity/transaction/Transaction.cpp"   "src/service/client/ClientService.h"  "src/service/client/ClientService.cpp" "src/service/account/AccountService.h" "src/repository/client/ClientRepository.h" "src/repository/client/ClientRepository.cpp"  "src/repository/account/AccountRepository.h" "src/repository/account/AccountRepository.cpp" "src/service/account/AccountService.cpp" "src/repository/citizen identify card/CitizenIdentifyCardRepository.h" "src/repository/citizen identify card/CitizenIdentifyCardRepository.cpp" "src/service/citizen identify card/CitizenIdentifyCardService.h" "src/service/citizen identify card/CitizenIdentifyCardService.cpp" "include/OracleQuery.h" "include/tool.h" "src/controller/citizen identify card/CitizenIdentifyCardController.h"  "src/dto/citizen identify card/CitizenIdentifyCardDTO.h" "src/repository/transaction/TransactionRepository.h" "src/repository/transaction/TransactionRepository.cpp" "src/service/transaction/TransactionService.h" "src/service/transaction/TransactionService.cpp" "src/exception/oracle/CustomOracleException.h" "src/exception/oracle/CustomOracleException.cpp" "src/dto/ResponseDTO.hpp" "src/controller/account/AccountController.h" "src/controller/client/ClientController.h" "src/dto/client/ClientRequest.h" "src/dto/client/ClientResponse.h" "include/define.h"  "src/dto/DTOs.hpp")

target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

set_target_properties(${project_name}-lib ${project_name}-exe ${project_name}-test PROPERTIES
        CXX_STANDARD 23
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

enable_testing()
add_test(project-tests ${project_name}-test)

