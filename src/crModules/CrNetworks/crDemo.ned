

package dos.crModules.CrNetworks;
import dos.crModules.RFSpectrum.datarateSpectrum;
import ned.DelayChannel;
import dos.core.*;
import dos.crModules.CrNodes.*;
import dos.crModules.PuNodes.*;

network crDemo extends baseCrNetwork
{
    @display("bgb=576,438,white;i=block/network2");
    submodules:
        CR1: BaseCrNode {
            @display("p=102,218;i=device/wifilaptop");
            address = 1;
            neighbors = "2 3 4 5 6";
        }
        CR2: BaseCrNode {
            @display("p=473,218;i=device/wifilaptop");
            address = 2;
            neighbors = "1 3 4 5 6";
        }
        //add_start
        CR3: BaseCrNode {
            @display("p=271,155;i=device/wifilaptop");
            address = 3;
            neighbors = "1 2 4 5 6";
        }
        CR4: BaseCrNode {
            @display("p=395,82;i=device/wifilaptop");
            address = 4;
            neighbors = "1 2 3 5 6";
        }
        CR5: BaseCrNode {
            @display("p=95,282;i=device/wifilaptop");
            address = 5;
            neighbors = "1 2 3 4 6";
        }
        CR6: BaseCrNode {
            @display("p=335,118;i=device/wifilaptop");
            address = 6;
            neighbors = "1 2 3 4 5";
        }
        //add_end
        gsm1: GSM {
            @display("p=281,92");
        }
        gsm2: GSM {
            @display("p=287,342");
        }
    connections:
        CR2.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR2.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR2.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR1.ports++;
        //add_start        
        CR3.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR4.ports++ <--> datarateSpectrum <--> CR3.ports++;
        CR4.ports++ <--> datarateSpectrum <--> CR5.ports++;
        CR5.ports++ <--> datarateSpectrum <--> CR6.ports++;
        CR6.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR3.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR1.ports++ <--> datarateSpectrum <--> CR4.ports++;
        CR4.ports++ <--> datarateSpectrum <--> CR6.ports++;
        CR5.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR4.ports++ <--> datarateSpectrum <--> CR6.ports++;
        CR3.ports++ <--> datarateSpectrum <--> CR6.ports++;
        CR2.ports++ <--> datarateSpectrum <--> CR4.ports++;
        CR5.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR5.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR4.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR4.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR5.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR6.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR5.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR6.ports++;
}

