#ifndef SENSORNODE_MODULE_H_
#define SENSORNODE_MODULE_H_

#include "opendavinci/odcore/base/FIFOQueue.h"
#include "opendavinci/odcore/base/module/TimeTriggeredConferenceClientModule.h"

#include "openbasn/model/sensor/Sensor.h"

using namespace std;

using namespace odcore::base;
using namespace odcore::base::module;

using namespace openbasn::model::sensor;

class SensorNodeModule : public TimeTriggeredConferenceClientModule {

    private:      
        SensorNodeModule(const SensorNodeModule &/*obj*/);
        SensorNodeModule& operator=(const SensorNodeModule &/*obj*/); 

    public:
        SensorNodeModule(const int32_t &argc, char **argv);
        virtual ~SensorNodeModule();
        odcore::data::dmcp::ModuleExitCodeMessage::ModuleExitCode body();

    private:
        virtual void setUp();
        virtual void tearDown();

        void getSensorConfiguration();
        void SensorNodeModule::sendSensorNodeData(SensorNodeData /*sensornodedata*/)
        void sendRequest(Request /*request*/);
        void processRequest(Request /*request*/);
        void processAcknowledge(Acknowledge /*acknowledge*/);

    private:
        uint32_t m_id;
        bool m_isRegistered;
        int32_t m_clock_tick;
        FIFOQueue m_buffer;

        vector<Sensor> m_sensor_vector;
        uint32_t m_number_of_sensors;

        string m_risk;
};

#endif