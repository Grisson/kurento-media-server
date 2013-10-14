/*
 * (C) Copyright 2013 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "KmsMediaServer_types.h"

namespace kurento
{

std::string generateUUID ();

KmsMediaServerException createKmsMediaServerException (std::string description);
KmsMediaServerException createKmsMediaServerException (int errorCode, std::string description);

int32_t getI32Param (const std::map<std::string, KmsMediaParam>& params, const std::string &paramName);

std::string getStringParam (const std::map<std::string, KmsMediaParam>& params, const std::string &paramName);
void setStringParam (std::map<std::string, KmsMediaParam>& params, const std::string &paramName, const std::string &paramValue);

const KmsMediaParam* getParam (const std::map<std::string, KmsMediaParam>& params, const std::string &paramName);

} // kurento

#endif /* __UTILS_HPP__ */