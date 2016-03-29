

import dos.core.*;
package dos.crModules.AppLayer;


simple crAppLayer extends BaseAppLayer like IAppLayer
{
    @class(crAppLayer);
    @signal[appRequests](type="long");  // The signals emited by app layer  // from int
    @statistic[appRequests](title="ApplicationRequests"; source="appRequests"; record=count);
    @signal[appSuccess](type="long");
    @statistic[appSuccess](title="ApplicationSessions"; source="appSuccess"; record=count);
    @signal[txDataSignal](type="int");
    @statistic[txDataSignal](title="TX Data"; source="txDataSignal"; record=count,count/60);
    @signal[txAckSignal](type="int");
    @statistic[txAckSignal](title="TX ACK"; source="txAckSignal"; record=count,count/60);
    @signal[rxDataSignal](type="int");
    @statistic[rxDataSignal](title="RX Data"; source="rxDataSignal"; record=count,count/60);
    @signal[rxAckSignal](type="int");
    @statistic[rxAckSignal](title="RX ACK"; source="rxAckSignal"; record=count,count/60);
    @signal[endSignal](type="simtime_t");
    @statistic[endSignal](title="Sim Time"; source="endSignal"; record=max);

    //@signal[packetRec](type="int");
    @display("i=block/app2");
}
