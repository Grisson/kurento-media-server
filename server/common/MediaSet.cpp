/*
 * MediaSet.cpp - Kurento Media Server
 *
 * Copyright (C) 2013 Kurento
 * Contact: Miguel París Díaz <mparisdiaz@gmail.com>
 * Contact: José Antonio Santos Cadenas <santoscadenas@kurento.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MediaSet.hpp"
#include "types/MediaFactory.hpp"
#include "types/MediaPlayer.hpp"
#include "types/MediaRecorder.hpp"
#include "types/Stream.hpp"
#include "types/Mixer.hpp"

namespace kurento
{

void
MediaSet::put (std::shared_ptr<MediaObject> mediaObject)
{
  mediaObjectMap.put (mediaObject->id, mediaObject );
}

void
MediaSet::remove (const MediaObject &mediaObject)
{
  mediaObjectMap.remove (mediaObject.id);
}

int
MediaSet::size ()
{
  return mediaObjectMap.size();
}

template std::shared_ptr<MediaFactory>
MediaSet::getMediaObject<MediaFactory> (const MediaObject &mediaObject);

template std::shared_ptr<Joinable>
MediaSet::getMediaObject<Joinable> (const MediaObject &mediaObject);

template std::shared_ptr<MediaSrc>
MediaSet::getMediaObject<MediaSrc> (const MediaObject &mediaObject);

template std::shared_ptr<MediaSink>
MediaSet::getMediaObject<MediaSink> (const MediaObject &mediaObject);

template std::shared_ptr<MediaPlayer>
MediaSet::getMediaObject<MediaPlayer> (const MediaObject &mediaObject);

template std::shared_ptr<MediaRecorder>
MediaSet::getMediaObject<MediaRecorder> (const MediaObject &mediaObject);

template std::shared_ptr<Stream>
MediaSet::getMediaObject<Stream> (const MediaObject &mediaObject);

template std::shared_ptr<Mixer>
MediaSet::getMediaObject<Mixer> (const MediaObject &mediaObject);

template std::shared_ptr<MixerPort>
MediaSet::getMediaObject<MixerPort> (const MediaObject &mediaObject);

template <class T> std::shared_ptr<T>
MediaSet::getMediaObject (const MediaObject &mediaObject)
{
  std::shared_ptr<MediaObject> mo;
  std::shared_ptr<T> typedMo;

  mo = mediaObjectMap.getValue (mediaObject.id);
  typedMo = std::dynamic_pointer_cast<T> (mo);

  if (typedMo == NULL)
    throw MediaObjectNotFoundException();

  return typedMo;
}

} // kurento
