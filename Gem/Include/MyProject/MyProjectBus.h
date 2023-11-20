
#pragma once

#include <MyProject/MyProjectTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace MyProject
{
    class MyProjectRequests
    {
    public:
        AZ_RTTI(MyProjectRequests, MyProjectRequestsTypeId);
        virtual ~MyProjectRequests() = default;
        // Put your public methods here
    };

    class MyProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using MyProjectRequestBus = AZ::EBus<MyProjectRequests, MyProjectBusTraits>;
    using MyProjectInterface = AZ::Interface<MyProjectRequests>;

} // namespace MyProject
