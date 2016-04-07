//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package dos.crModules.CrNetworks;
import dos.crModules.RFSpectrum.datarateSpectrum;
import ned.DelayChannel;
import dos.core.*;
import dos.crModules.CrNodes.*;
import dos.crModules.PuNodes.*;
import dos.crModules.Attacker.*;

network test_DoS extends baseCrNetwork
{
    parameters:
//        int numNodes; // total number of hosts in the network

        @display("bgb=576,438,white;i=block/network2");
    submodules:
        CR1: BaseCrNode {
            @display("p=86,115;i=device/wifilaptop");
            address = 1;
            neighbors = "2 3 4 5 6 7 8 9 10";
        }
        CR2: BaseCrNode {
            @display("p=473,218;i=device/wifilaptop");
            address = 2;
            neighbors = "1 3 4 5 6 7 8 9 10";
        }
        //add_start
        CR3: BaseCrNode {
            @display("p=271,155;i=device/wifilaptop");
            address = 3;
            neighbors = "1 2 4 5 6 7 8 9 10";
        }
        CR4: BaseCrNode {
            @display("p=395,82;i=device/wifilaptop");
            address = 4;
            neighbors = "1 2 3 5 6 7 8 9 10";
        }
        CR5: BaseCrNode {
            @display("p=95,282;i=device/wifilaptop");
            address = 5;
            neighbors = "1 2 3 4 6 7 8 9 10";
        }
        CR6: BaseCrNode {
            @display("p=335,118;i=device/wifilaptop");
            address = 6;
            neighbors = "1 2 3 4 5 7 8 9 10";
        }
        CR7: BaseCrNode {
            @display("p=199,342;i=device/wifilaptop");
            address = 7;
            neighbors = "1 2 3 4 5 6 8 9 10";
        }
        CR8: BaseCrNode {
            @display("p=454,137;i=device/wifilaptop");
            address = 8;
            neighbors = "1 2 3 4 5 6 7 9 10";
        }
        CR9: BaseCrNode {
            @display("p=199,82;i=device/wifilaptop");
            address = 9;
            neighbors = "1 2 3 4 5 6 7 8 10";
        }
        CR10: BaseCrNode {
            @display("p=296,235;i=device/wifilaptop");
            address = 10;
            neighbors = "1 2 3 4 5 6 7 8 9";
        }
        //add_end
        gsm1: GSM {
            @display("p=281,92");
        }
        gsm2: GSM {
            @display("p=287,342");
        }
        gsm3: GSM {
            @display("p=172,137");
        }
        gsm4: GSM {
            @display("p=199,271");
        }
        gsm5: GSM {
            @display("p=362,271");
        }

        attacker1: sillyDoS {
            @display("p=222,217");
        }
        attacker2: sillyDoS {
            @display("p=111,300");
        }
        attacker3: sillyDoS {
            @display("p=90,180");
        }
    connections:
        gsm1.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR2.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR4.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR5.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR6.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR7.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR8.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR9.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR10.ports++;

        gsm2.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR2.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR4.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR5.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR6.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR7.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR8.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR9.ports++;
        gsm2.ports++ <--> datarateSpectrum <--> CR10.ports++;

        gsm3.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR2.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR4.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR5.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR6.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR7.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR8.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR9.ports++;
        gsm3.ports++ <--> datarateSpectrum <--> CR10.ports++;

        gsm4.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR2.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR4.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR5.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR6.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR7.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR8.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR9.ports++;
        gsm4.ports++ <--> datarateSpectrum <--> CR10.ports++;

        gsm5.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR2.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR3.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR4.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR5.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR6.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR7.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR8.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR9.ports++;
        gsm5.ports++ <--> datarateSpectrum <--> CR10.ports++;

        CR2.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR3.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR4.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR5.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR6.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR7.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR8.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR9.ports++ <--> datarateSpectrum <--> CR1.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR1.ports++;

        CR3.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR4.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR5.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR6.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR7.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR8.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR9.ports++ <--> datarateSpectrum <--> CR2.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR2.ports++;

        CR4.ports++ <--> datarateSpectrum <--> CR3.ports++;
        CR5.ports++ <--> datarateSpectrum <--> CR3.ports++;
        CR6.ports++ <--> datarateSpectrum <--> CR3.ports++;
        CR7.ports++ <--> datarateSpectrum <--> CR3.ports++;
        CR8.ports++ <--> datarateSpectrum <--> CR3.ports++;
        CR9.ports++ <--> datarateSpectrum <--> CR3.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR3.ports++;

        CR5.ports++ <--> datarateSpectrum <--> CR4.ports++;
        CR6.ports++ <--> datarateSpectrum <--> CR4.ports++;
        CR7.ports++ <--> datarateSpectrum <--> CR4.ports++;
        CR8.ports++ <--> datarateSpectrum <--> CR4.ports++;
        CR9.ports++ <--> datarateSpectrum <--> CR4.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR4.ports++;

        CR6.ports++ <--> datarateSpectrum <--> CR5.ports++;
        CR7.ports++ <--> datarateSpectrum <--> CR5.ports++;
        CR8.ports++ <--> datarateSpectrum <--> CR5.ports++;
        CR9.ports++ <--> datarateSpectrum <--> CR5.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR5.ports++;
        
        CR7.ports++ <--> datarateSpectrum <--> CR6.ports++;
        CR8.ports++ <--> datarateSpectrum <--> CR6.ports++;
        CR9.ports++ <--> datarateSpectrum <--> CR6.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR6.ports++;
        
        CR8.ports++ <--> datarateSpectrum <--> CR7.ports++;
        CR9.ports++ <--> datarateSpectrum <--> CR7.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR7.ports++;
        
        CR9.ports++ <--> datarateSpectrum <--> CR8.ports++;
        CR10.ports++ <--> datarateSpectrum <--> CR8.ports++;
        
        CR10.ports++ <--> datarateSpectrum <--> CR9.ports++;

        attacker1.ports++ <--> datarateSpectrum <--> CR1.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR2.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR3.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR4.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR5.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR6.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR7.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR8.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR9.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR10.ports++;

        attacker2.ports++ <--> datarateSpectrum <--> CR1.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR2.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR3.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR4.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR5.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR6.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR7.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR8.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR9.ports++;
        attacker2.ports++ <--> datarateSpectrum <--> CR10.ports++;

        attacker3.ports++ <--> datarateSpectrum <--> CR1.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR2.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR3.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR4.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR5.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR6.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR7.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR8.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR9.ports++;
        attacker3.ports++ <--> datarateSpectrum <--> CR10.ports++;
}

