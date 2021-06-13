/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
//#include <utils/Log.h>
//#include <string>
//#include <utils/String8.h>
//#include <utils/String16.h>

#include "property_service.h"
#include "vendor_init.h"

//using android::String8;
//using android::String16;
using android::init::property_set;

//String16 mClientPackageName;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void load_begoniaglobal() {
        property_override("ro.build.fingerprint", "google/coral/coral:11/RQ2A.210505.002/7246365:user/release-keys");
        property_override("ro.product.board", "begonia");
        property_override("ro.product.device", "begonia");
        property_override("ro.product.model", "Redmi Note 8 Pro");
        property_override("ro.product.system.model", "Redmi Note 8 Pro");
        property_override("ro.product.vendor.model", "Redmi Note 8 Pro");
}

void load_begoniain() {
        property_override("ro.build.fingerprint", "google/coral/coral:11/RQ2A.210505.002/7246365:user/release-keys");
        property_override("ro.product.board", "begoniain");
        property_override("ro.product.device", "begoniain");
        property_override("ro.product.model", "Redmi Note 8 Pro");
        property_override("ro.product.system.model", "Redmi Note 8 Pro");
        property_override("ro.product.vendor.model", "Redmi Note 8 Pro");
}

void load_begonia() {
        property_override("ro.build.fingerprint", "google/coral/coral:11/RQ2A.210505.002/7246365:user/release-keys");
        property_override("ro.product.board", "begonia");
        property_override("ro.product.device", "begonia");
        property_override("ro.product.model", "Redmi Note 8 Pro");
        property_override("ro.product.system.model", "Redmi Note 8 Pro");
        property_override("ro.product.vendor.model", "Redmi Note 8 Pro");
}

void vendor_load_properties() {
    std::string region = android::base::GetProperty("ro.boot.hwc", "");

    if (region.find("CN") != std::string::npos) {
        load_begonia();
    } else if (region.find("India") != std::string::npos) {
        load_begoniain();
    } else if (region.find("GL") != std::string::npos) {
        load_begoniaglobal();
    } else {
        LOG(ERROR) << __func__ << ": unexcepted region!";
    }

    property_override("ro.oem_unlock_supported", "0");
    // Fix some apps identification
    property_override("ro.product.vendor.model", "begonia");
    property_override("ro.product.system.model", "begonia");
}

    // Configure codec for Facebook apps
//void facebook_load_properties() {
//
//    if (strcmp(String8(mClientPackageName).string(), "com.instagram.android") == 0) {
//        property_override("debug.stagefright.omx_default_rank", "1000");
//        ALOGI("Enabling ccodec");
//    } else {
//        property_override("debug.stagefright.omx_default_rank", "0");
//        ALOGI("Disabling ccodec");
//    }
//}
