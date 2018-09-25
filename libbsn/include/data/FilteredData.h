#ifndef FILTERED_DATA_H_
#define FILTERED_DATA_H_

#include "opendavinci/odcore/data/SerializableData.h"
#include "opendavinci/odcore/serialization/Deserializer.h"
#include "opendavinci/odcore/serialization/SerializationFactory.h"
#include "opendavinci/odcore/serialization/Serializer.h"

#include <sys/time.h>
#include <vector>

namespace bsn {
    namespace data {
        
        class FilteredData : public odcore::data::SerializableData {
        
            public:
                //construtor parametrizado
                FilteredData(const double &/*filtered data*/, const std::string &, const std::array<timespec, 3> &);

                FilteredData();            // construtor
                virtual ~FilteredData();   // destrutor

                //Boas práticas do manual do OpenDaVINCI
                FilteredData(const FilteredData & /*obj*/);
                FilteredData& operator=(const FilteredData &/*obj*/);
            
            // Métodos abstratos
            public:
                virtual int32_t getID() const;
                virtual const std::string getShortName() const;
                virtual const std::string getLongName() const;

                static int32_t ID();
                static const std::string ShortName();
                static const std::string LongName();
        
            public:
                virtual std::ostream& operator<<(std::ostream &out) const;
                virtual std::istream& operator>>(std::istream &in);
        
                virtual const std::string toString() const;
                
            // setters e getters
            public:
                void setSensorData(const double &/*sensor_data*/);
                double getSensorData() const;

                void setSensorType(const std::string &);
                std::string getSensorType() const;

                void setTimespec(const std::array<timespec, 3> &);
                std::array<timespec, 3> getTimespec() const;
            
            private:
                double m_sensor_data; // estado do sensor
                std::string sensorType;
                std::array<timespec, 3> time_v;
        };
    }
}

#endif