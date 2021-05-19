/******************************************************************************
 * Copyright 2018 Google
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
// This file contains your configuration used to connect to Cloud IoT Core

// Wifi network details.
const char *ssid = "SSID";
const char *password = "PASSWORD";

// Cloud iot details.
const char *project_id = "project-id"; // enter your project id
const char *location = "us-central1";
const char *registry_id = "my-registry";
const char *device_id = "my-esp32-device";

// Configuration for NTP
const char* ntp_primary = "pool.ntp.org";
const char* ntp_secondary = "time.nist.gov";

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

// To get the private key run (where private-key.pem is the ec private key
// used to create the certificate uploaded to google cloud iot):
// openssl ec -in <private-key.pem> -noout -text
// and copy priv: part.
// The key length should be exactly the same as the key length bellow (32 pairs
// of hex digits). If it's bigger and it starts with "00:" delete the "00:". If
// it's smaller add "00:" to the start. If it's too big or too small something
// is probably wrong with your key.
const char *private_key_str =
    "6e:b8:17:35:c7:fc:6b:d7:a9:cb:cb:49:7f:a0:67:"
    "63:38:b0:90:57:57:e0:c0:9a:e8:6f:06:0c:d9:ee:"
    "31:41";

// Time (seconds) to expire token += 20 minutes for drift
const int jwt_exp_secs = 60*20; // Maximum 24H (3600*24)

// To get the certificate for your region run:
//   openssl s_client -showcerts -connect mqtt.googleapis.com:8883
// for standard mqtt or for LTS:
//   openssl s_client -showcerts -connect mqtt.2030.ltsapis.goog:8883
// Copy the certificate (all lines between and including ---BEGIN CERTIFICATE---
// and --END CERTIFICATE--) to root.cert and put here on the root_cert variable.

const char *root_cert =
    "-----BEGIN CERTIFICATE-----\n"
    "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"
    "bUqmB/fgLmze65rW0QP8xmP1HCOgYoVv6qOtug=="
    "-----END CERTIFICATE-----\n";

// In case we ever need extra topics
const int ex_num_topics = 0;
const char* ex_topics[ex_num_topics];
//const int ex_num_topics = 1;
//const char* ex_topics[ex_num_topics] = {
//  "/devices/my-device/tbd/#"
//};