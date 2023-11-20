
#include <AzCore/Serialization/SerializeContext.h>

#include "MyProjectSystemComponent.h"

#include <MyProject/MyProjectTypeIds.h>

namespace MyProject
{
    AZ_COMPONENT_IMPL(MyProjectSystemComponent, "MyProjectSystemComponent",
        MyProjectSystemComponentTypeId);

    void MyProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<MyProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void MyProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("MyProjectService"));
    }

    void MyProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("MyProjectService"));
    }

    void MyProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void MyProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    MyProjectSystemComponent::MyProjectSystemComponent()
    {
        if (MyProjectInterface::Get() == nullptr)
        {
            MyProjectInterface::Register(this);
        }
    }

    MyProjectSystemComponent::~MyProjectSystemComponent()
    {
        if (MyProjectInterface::Get() == this)
        {
            MyProjectInterface::Unregister(this);
        }
    }

    void MyProjectSystemComponent::Init()
    {
    }

    void MyProjectSystemComponent::Activate()
    {
        MyProjectRequestBus::Handler::BusConnect();
    }

    void MyProjectSystemComponent::Deactivate()
    {
        MyProjectRequestBus::Handler::BusDisconnect();
    }
}
