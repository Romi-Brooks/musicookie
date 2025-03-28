#ifndef BLOCK_HPP
#define BLOCK_HPP

/* Block 是什么:
 * Block 是musicookie中最基本的单元
 * Block 分为AudioBlock和MidiBlock
 * AudioBlock用于接受一个音频信号，然后将其发送到BlockFX中
 * MidiBlock用于接受一个Midi信号，通过波形发生器处理成音频信号之后将其发送到BlockFX中
 */

class Block {
    public:
        virtual ~Block() = default; // 虚析构函数，确保多态删除

        // User Interface Virtual Function
        virtual double GetLength() const = 0;
        virtual std::string GetType() const = 0;
};

class AudioBlock : public Block {
    private:
        std::vector<float> AudioSampleData;
        double AudioSampleRate;
        double AudioBlockLength;
        std::string AudioBlockName;

    public:
        AudioBlock(std::string I_AudioBlockName, double I_SampleRate);

        // User Action Interface

        // User Interface
        double GetLength() const override {return AudioBlockLength;}
        std::string GetType() const override {return "AudioBlock";}
};

class MidiBlock : public Block {
    private:
        struct MidiEvent {
            double MidiTime;          // 事件时间（秒）
            int MidiNote;             // 音符（MIDI音符编号）
            int MidiVelocity;         // 音符力度
            std::string MidiType;     // 事件类型（note_on, note_off, control_change等）
        };
        std::vector<MidiEvent> MIDIEvent; // MIDI事件
        double MidiBlockLength;            // 总长度（秒）
        std::string MidiBlockName; // MIDI块名称

    public:
        MidiBlock(std::string  I_MIDIBlockName) : MidiBlockLength(0.0), MidiBlockName(std::move(I_MIDIBlockName)) {}

        // User Action Interface
        // 添加MIDI事件
        void AddMidiEvent(double I_MidiTime, int I_MidiNote, int I_MidiVelocity, const std::string& I_MidiType);

        // User Interface
        double GetLength() const override {return MidiBlockLength;}
        std::string GetType() const override {return "MidiBlock";}
};



#endif //BLOCK_HPP
