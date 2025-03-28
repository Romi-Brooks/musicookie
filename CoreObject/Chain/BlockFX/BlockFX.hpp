#ifndef BLOCKFX_HPP
#define BLOCKFX_HPP
/* BlockFX 是什么:
 * 先来放在这里，至于内容之后再来写
 * Block本身没有处理音频信号的能力，只是用于接受和发送信号
 * 所以在这里引入BlockFX，用于处理音频信号(姑且先称为Pre-FX)
 * 在这里BlockFX只接受和发送信号，并且进行简单处理(如Volume, Pan, Mute, Solo的处理)
 * 在之后，发送到Mixer类中进行下一步的细致处理
 */

class BlockFX {
    private:
        AudioBlock* AudioBlockIN; // 输入的音频信号源
        MidiBlock* MIDIBlockIN; // 输入的MIDI音频信号源

        float BlockVolume;
        int BlockPan;

        double* AudioOut;
        double* MIDIAuidoOut;

    public:
    // Default Constructor
    BlockFX(AudioBlock* I_AudioBlock, MidiBlock* I_MIDIBlock) : AudioBlockIN(I_AudioBlock), MIDIBlockIN(I_MIDIBlock), BlockVolume(1.0f), BlockPan(0) {
        AudioOut = new double[1024]; // Buffer size of 1024 samples
        MIDIAuidoOut = new double[1024]; // Buffer size of 1024 samples
    }

    // Destructor
    ~BlockFX() {
        delete[] AudioOut;
        delete[] MIDIAuidoOut;
    }

    // Basic Functions
    void SetVolume(float I_BlockVolume);
    void SetPan(int I_BlockPan);

    // 用于处理音频信号和MIDI音频信号
    // 需要注意的是，在Block类中，也需要有对应的GetAudioOut和GetMIDIAudioOut函数
    // Core Function
    void ProcessAudio();
    void ProcessMIDI();

    // Another Chain Interfaces
    auto ReturnAudio() const{return AudioOut;}; // 返回处理后的音频信号
    auto ReturnMIDIAudio() const {return MIDIAuidoOut;}; // 返回处理后的MIDI音频信号

    // User Interfaces
    void SendToMixer(Mixer& Global_Mixer, unsigned int I_ChannelID); // 将处理后的信号发送到Mixer的Audio_IN
};



#endif //BLOCKFX_HPP
