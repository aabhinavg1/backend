#pragma once

// oatpp
#include <oatpp/macro/codegen.hpp>
#include <oatpp/macro/component.hpp>

#include "oatpp/web/server/api/ApiController.hpp"

// service

#include "service/citizen identify card/CitizenIdentifyCardService.h"

// dto
#include "dto/DTOs.hpp"
#include "dto/ResponseDTO.hpp"
#include "dto/citizen identify card/CitizenIdentifyCardDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CitizenIdentifyCardController : public oatpp::web::server::api::ApiController {
 public:
  CitizenIdentifyCardController(OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMapper))
      : oatpp::web::server::api::ApiController(apiContentMapper, "cic") {}

  ENDPOINT("POST", "/create", create, BODY_DTO(Object<CitizenIdentifyCardDTO>, request)) {
    auto result = ResponseDTO::createShared(service::CitizenIdentifyCardService::add(request->to_obj()));
    return createDtoResponse(Status::CODE_200, result);
  }

  ENDPOINT("GET", "/{number}", get, PATH(Int64, number)) {
    auto temp = service::CitizenIdentifyCardService::get(number);
    if (temp) {
      return createDtoResponse(
          Status::CODE_200, ResponseDTO::createShared(CitizenIdentifyCardDTO::createShared(std::move(temp).value())));
    } else {
      return createDtoResponse(Status::CODE_404, ResponseDTO::createShared(404, "not found"));
    }
    // return createDtoResponse(Status::CODE_200, MyDto::createShared(200, ""));
  }

  ENDPOINT("PUT", "/update/{number}", update, PATH(Int64, number), BODY_DTO(Object<CitizenIdentifyCardDTO>, new_obj)) {
    return createResponse(Status::CODE_200, "");
  }

  ENDPOINT("DELETE", "/delete/{number}", delete_, PATH(Int64, number)) {
    auto check = service::CitizenIdentifyCardService::delete_by_id(number);
    auto result = ResponseDTO::createShared(check);
    return createDtoResponse(Status(result->status_code, ""), result);
  }
};

#include OATPP_CODEGEN_END(ApiController)
