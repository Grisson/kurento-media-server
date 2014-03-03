/* Autogenerated with Kurento Idl */

#include <memory>

#include "MediaPipeline.hpp"
#include <JsonSerializer.hpp>

namespace kurento {

std::shared_ptr<MediaObject> MediaPipeline::Factory::createObject (const Json::Value &params)
{
  int garbagePeriod = 0;

  if (!params.isMember ("garbagePeriod")) {
    /* param 'garbagePeriod' not present, using default */
    garbagePeriod = 120;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(garbagePeriod);
  }

  return createObject (garbagePeriod);
}

MediaPipeline::Factory::StaticConstructor MediaPipeline::Factory::staticConstructor;

MediaPipeline::Factory::StaticConstructor::StaticConstructor()
{
  if (objectRegistrar) {
    std::shared_ptr <Factory> factory (new MediaPipeline::Factory());

    objectRegistrar->registerFactory(factory);
  }
}

void
MediaPipeline::Invoker::invoke (std::shared_ptr<MediaObject> obj,
    const std::string &methodName, const Json::Value &params,
    Json::Value &response)
{
  MediaObject::Invoker::invoke(obj, methodName, params, response);
}

std::string
MediaPipeline::connect(const std::string &eventType, std::shared_ptr<EventHandler> handler)
{
  return MediaObject::connect (eventType, handler);
}

} /* kurento */

void
Serialize(std::shared_ptr<kurento::MediaPipeline> &object, JsonSerializer &serializer)
{
  if (!serializer.IsWriter) {
    try {
      std::shared_ptr<kurento::MediaObject> aux;
      aux = kurento::MediaPipeline::Factory::getObject (serializer.JsonValue.asString ());
      object = std::dynamic_pointer_cast<kurento::MediaPipeline> (aux);
      return;
    } catch (kurento::JsonRpc::CallException &ex) {
      kurento::JsonRpc::CallException e (kurento::JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'MediaPipeline' object not found: "+ ex.getMessage());
      throw e;
    }
  }
  std::shared_ptr<kurento::MediaObject> aux = std::dynamic_pointer_cast<kurento::MediaObject> (object);

  void Serialize(std::shared_ptr<kurento::MediaObject> &object, JsonSerializer &serializer);
  Serialize(aux, serializer);
}

void
Serialize(kurento::MediaPipeline &object, JsonSerializer &serializer)
{
  void Serialize(kurento::MediaObject &object, JsonSerializer &serializer);
  try {
    Serialize(dynamic_cast<kurento::MediaObject &> (object), serializer);
  } catch (std::bad_cast) {
  }
}