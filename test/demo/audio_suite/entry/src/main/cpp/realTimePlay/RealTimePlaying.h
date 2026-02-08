/*
 * Copyright (c) 2025 Huawei Device Co., Ltd. 2025-2025. ALL rights reserved.
 */

#ifndef AUDIOEDITTESTAPP_REALTIMEPLAYING_H
#define AUDIOEDITTESTAPP_REALTIMEPLAYING_H

#include "ohaudiosuite/native_audio_suite_base.h"
#include "ohaudio/native_audiostream_base.h"
#include <cstdint>
#include "napi/native_api.h"
#include <string>
#include <atomic>
#include <mutex>

// Buffer size constant
constexpr int MAX_PLAY_RESULT_BUFFER_SIZE = 1024 * 1024 * 100;

extern OH_AudioRenderer *audioRenderer;

extern OH_AudioStreamBuilder *rendererBuilder;

// Real-time playback   if the rendering completed in one go
extern std::atomic<bool> g_playFinishedFlag;

extern int32_t g_playDataSize;

extern char *g_playAudioData;

// Record or not?
extern std::atomic<bool> g_isRecord;

// Real-time playback, used for saving audio data
// with the specific size varying according to the size of the file to be saved
extern char *g_playTotalAudioData;

// Total size of audio to be saved for real-time playback
extern int32_t g_playResultTotalSize;

// Mutex for protecting shared data access between audio thread and main thread
extern std::mutex g_playDataMutex;

extern OH_AudioDataArray* g_playOhAudioDataArray;
 
extern uint32_t g_separationMode;

OH_AudioSuite_Result ProcessPipeline();

OH_AudioSuite_Result OneRenDerFrame(int32_t audioDataSize, int32_t *writeSize);

OH_AudioSuite_Result OneMulRenDerFrame(int32_t audioDataSize, int32_t *writeSize);

OH_AudioData_Callback_Result PlayAudioRendererOnWriteData(OH_AudioRenderer *renderer,
    void *userData, void *audioData, int32_t audioDataSize);

napi_value ModifyRenderTrack(napi_env env, napi_callback_info info);

void ReleaseExistingResources();

#endif //AUDIOEDITTESTAPP_REALTIMEPLAYING_H