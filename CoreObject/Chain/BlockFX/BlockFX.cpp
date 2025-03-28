#include "../../Mixer/Mixer.hpp"
#include "../../Block/Block.hpp"
#include "../../../IOSystem/Log/Log.hpp"
#include "BlockFX.hpp"

void BlockFX::SetVolume(float I_BlockVolume) {
    this->BlockVolume = I_BlockVolume;
}
void BlockFX::SetPan(int I_BlockPan) {
    this->BlockPan = I_BlockPan;
}

// 将处理后的信号发送到Mixer的MixerAudioIn
void BlockFX::SendToMixer(Mixer& Global_Mixer, unsigned int I_ChannelID) {
    double* MixerAudioIn = Global_Mixer.GetMixerChannelAudioIn(I_ChannelID); // 获取Mixer通道的Audio_IN指针
    // 将处理后的音频信号复制到Mixer的Audio_IN
    for (int i = 0; i < 1024; i++) {
        MixerAudioIn[i] = AudioOut[i];
    }
    LOG_INFO("BlockFX: Sent audio to Mixer channel " + I_ChannelID);
}
