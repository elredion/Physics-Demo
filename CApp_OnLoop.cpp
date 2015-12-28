#include "CApp.h"

void CApp::OnLoop() {

    CFPS::FPSControl.OnLoop();

    for(size_t i = 0; i < CEntity::EntityList.size(); i++)
    {
        CEntity::EntityList[i]->SetCenter();
        if(CEntity::EntityList[i]->InvMass > 0) CEntity::EntityList[i]->Vel.SetY(GRAV);
    }

    for(size_t i = CEntity::EntityList.size() - 1; i >= 0; i--)
    {
        for(size_t j = i-1; j >= 0; j--)
            CContact::ContactList.push_back(CEntity::EntityList[i]->GenerateContact(CEntity::EntityList[j]));
    }

    for(size_t i = 0; i < CContact::ContactList.size(); i++)
    {
        CContact Contact = CContact::ContactList[i];
        if(Contact.EntityA != NULL && Contact.EntityA != NULL)
        {
            float relNv = Contact.RelV.Dot(Contact.Normal);
            float SpecDist = relNv + 0.4 * (Contact.Distance + 1) / CFPS::FPSControl.GetSpeedFactor();
            if (SpecDist < 0 && Contact.Distance < 0)
            {
                float Impulse = SpecDist / (Contact.EntityA->InvMass + Contact.EntityB->InvMass);
                Contact.EntityA->Vel += Contact.Normal * Contact.EntityA->InvMass * Impulse;
                Contact.EntityB->Vel += (Contact.Normal * Contact.EntityB->InvMass * -Impulse);
            }
        }
    }

    for(size_t i = 0; i < CEntity::EntityList.size(); i++)
    {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }


    CContact::ContactList.clear();
}
