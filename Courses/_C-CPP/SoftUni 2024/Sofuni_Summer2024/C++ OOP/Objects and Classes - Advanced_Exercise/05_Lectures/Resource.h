//
// Created by User on Сб-6.7.2024 г..
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"
#include <iostream>
using SoftUni::ResourceType;

namespace SoftUni{


    class Resource{
        friend std::istream& operator>>(std::istream&, Resource&);
        friend std::ostream& operator<<(std::ostream&, Resource);
        friend bool operator<(const Resource&, const Resource&);

    private:
        int m_ID;
        ResourceType m_RT;
        std::string m_LINK;


    public:
        Resource(int id =0, ResourceType rt =PRESENTATION, std::string link ="") :
        m_ID(id),
        m_RT(rt),
        m_LINK(std::move(link)){}

//      getters
        int getId() const { return m_ID; }
        enum ResourceType getType() const { return m_RT; }
        std::string getLink() const { return m_LINK; }

//      setters
        void setID(int id) { m_ID = id; }
        void setRT(ResourceType rt) { m_RT = rt; }
        void setLink(std::string lnk) { m_LINK = lnk; }

    };

    std::istream& operator>>(std::istream& IN, Resource& obj){
        int tempID;
        char c;
        enum ResourceType tempRT;
        std::string tempLink;

        IN >> tempID;
        obj.setID(tempID);

        IN >> c;
        switch (c) {
            case 'P':
                tempRT = ResourceType::PRESENTATION;
                break;
            case 'D':
                tempRT = ResourceType::DEMO;
                break;
            case 'V':
                tempRT = ResourceType::VIDEO;
                break;
            default:
                break;
        }

        obj.setRT(tempRT);

        std::cin >> tempLink;
        std::getline(std::cin, tempLink);
        obj.setLink(tempLink);

        return IN;
    }


    std::ostream& operator<<(std::ostream& out, Resource obj){
        out << obj.getId() << " " << obj.getType() << obj.getLink();
        return out;
    }
















}



#endif //!RESOURCE_H
