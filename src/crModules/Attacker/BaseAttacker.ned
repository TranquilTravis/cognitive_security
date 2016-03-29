

package dos.crModules.Attacker;
import dos.core.*;

module BaseAttacker
{
    parameters:
        int Channel = default(0);
        bool AttackEnabled = default(false);
        double arrivalRate = default(0.5);
        double TxDuration = default(5.0);
        string Type;// = default("testPU");
        int address = default(1);
        @display("i=device/antennatower");

    gates:
        inout ports[];

    submodules:
        appLayer: <Type> like IAttacker;
    connections:
        for i=0..sizeof(ports)-1 {
            appLayer.radio++ <--> ports[i];
        }
}
