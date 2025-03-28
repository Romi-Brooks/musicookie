#include <iostream>
#include "CoreObject/Mixer/Mixer.hpp"

int main() {
    Mixer Global_Mixer;
    Global_Mixer.AddMixerChannel("Kick");
    Global_Mixer.AddMixerChannel("Hi-Hat");
    Global_Mixer.AddMixerChannel("Snare");
    Global_Mixer.AddMixerChannel("Clap");
    Global_Mixer.Mixer_Printer();
    return 0;
}
