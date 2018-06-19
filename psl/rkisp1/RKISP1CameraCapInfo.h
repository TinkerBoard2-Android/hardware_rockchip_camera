/*
 * Copyright (C) 2014-2017 Intel Corporation
 * Copyright (c) 2017, Fuzhou Rockchip Electronics Co., Ltd
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

#ifndef _CAMERA3_HAL_RKISP1CAMERACAPINFO_H_
#define _CAMERA3_HAL_RKISP1CAMERACAPINFO_H_

#include <string>
#include <vector>
#include "PlatformData.h"
#include "MediaCtlPipeConfig.h"

namespace android {
namespace camera2 {

class GraphConfigNodes;

class RKISP1CameraCapInfo : public CameraCapInfo {
public:
    RKISP1CameraCapInfo(SensorType type);
    ~RKISP1CameraCapInfo();
    virtual int sensorType(void) const { return mSensorType; }
    bool exposureSyncEnabled(void) const { return mExposureSync; };
    bool digiGainOnSensor(void) const { return mDigiGainOnSensor; };
    bool gainExposureCompEnabled(void) const { return mGainExposureComp; };
    int gainLag(void) const { return mGainLag; };
    int exposureLag(void) const { return mExposureLag; };
    const float* fov(void) const { return mFov; };
    int statisticsInitialSkip(void) const { return mStatisticsInitialSkip; };
    int frameInitialSkip(void) const { return mFrameInitialSkip; };
    int getCITMaxMargin(void) const { return mCITMaxMargin; };
    bool getSupportIsoMap(void) const { return mSupportIsoMap; }
    const char* getNvmDirectory(void) const { return mNvmDirectory.c_str(); };
    const char* getSensorName(void) const { return mSensorName.c_str(); };
    const ia_binary_data getNvmData(void) const { return mNvmData; };
    const std::string& getGraphSettingsFile(void) const { return mGraphSettingsFile; };
    const std::string getTestPatternBayerFormat(void) const { return mTestPatternBayerFormat; };
    const std::string& getIqTuningFile(void) const { return mIqTuningFile; };

    const std::string getMediaCtlEntityName(std::string type) const;
    const std::vector<std::string> getMediaCtlEntityNames(std::string type) const;
    const std::string getMediaCtlEntityType(std::string name) const;

    int mSensorType;
    int mSensorFlipping;
    bool mExposureSync;
    bool mDigiGainOnSensor;
    bool mGainExposureComp;
    int mGainLag;
    int mExposureLag;
    float mFov[2]; /* mFov[0] is fov horizontal, mFov[1] is fov vertical */
    int mFrameInitialSkip;
    int mStatisticsInitialSkip;
    int mCITMaxMargin;
    bool mSupportIsoMap;
    std::string mNvmDirectory;
    std::string mSensorName;
    ia_binary_data mNvmData;
    std::string mGraphSettingsFile;
    std::string mTestPatternBayerFormat;

    std::string mIqTuningFile;
private:
    friend class PSLConfParser;
    std::vector<MediaCtlElement> mMediaCtlElements;
};

const RKISP1CameraCapInfo * getRKISP1CameraCapInfo(int cameraId);

} // namespace camera2
} // namespace android
#endif // _CAMERA3_HAL_RKISP1CAMERACAPINFO_H_
