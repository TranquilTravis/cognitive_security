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

network TestAtt extends baseCrNetwork
{
    parameters:
//        int numNodes; // total number of hosts in the network

        @display("bgb=576,438,white;i=block/network2");
    submodules:
        CR1: BaseCrNode {
            @display("p=102,218;i=device/wifilaptop");
            address = 1;
            neighbors = "2";
        }
        CR2: BaseCrNode {
            @display("p=473,218;i=device/wifilaptop");
            address = 2;
            neighbors = "1";
        }

        gsm1: GSM {
            @display("p=281,92");
        }

        attacker1: sillyDoS {
            @display("p=229,182");
        }
    connections:
        CR2.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR1.ports++;
        gsm1.ports++ <--> datarateSpectrum <--> CR2.ports++;

        attacker1.ports++ <--> datarateSpectrum <--> CR1.ports++;
        attacker1.ports++ <--> datarateSpectrum <--> CR2.ports++;
}

