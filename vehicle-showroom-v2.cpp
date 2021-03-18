#include <iostream>
#include <string>
#include <vector>

using namespace std;





class ModelNumber
{
public:
    string model;
};

class EngineType
{
public:
    string type;
};

class EnginePower
{
public:
    float power;
};

class TireSize
{
public:
    int size;
};

class TurboCharger
{
public:
    int turbo;
};

class Weight
{
public:
    float weight;
};





class Vehicle
{
public:
    ModelNumber* modelNumber;
    EngineType* engineType;
    EnginePower* enginePower;
    TireSize* tireSize;
    TurboCharger* turboCharger;
    Weight* weight;

    void specifications()
    {
        cout << endl;
        cout << "Model Number: " << modelNumber->model << endl;
        cout << "Engine Type: " << engineType->type << endl;
        cout << "Engine Power: " << enginePower->power << endl;
        cout << "Tire Size: " << tireSize->size << endl;
        if(turboCharger->turbo > 0) cout << "Turbo: " << turboCharger->turbo << endl;
        if(weight->weight > 0) cout << "Weight: " << weight->weight << endl;
    }
};





/* The Builder object specifies the interface for creating parts of the complex object. */
class Builder
{
public:
    virtual ModelNumber* getModelNumber() = 0;
    virtual EngineType* getEngineType() = 0;
    virtual EnginePower* getEnginePower() = 0;
    virtual TireSize* getTireSize() = 0;
    virtual TurboCharger* getTurboCharger() = 0;
    virtual Weight* getWeight() = 0;
};





class NormalVehicleBuilder : public Builder
{
public:
    ModelNumber* getModelNumber()
    {
        ModelNumber* modelNumber = new ModelNumber();


        system("cls");
        cout << "Enter the model number of the BASIC vehicle (string): " << endl << "==>";
        string s; cin >> s;

        modelNumber->model = s;
        return modelNumber;
    }

    EngineType* getEngineType()
    {
        EngineType* engineType = new EngineType();

        cout << endl;
        cout << "Engine type: (Enter only the characters a/b/c)" << endl << "a. oil" << endl << "b. gas" << endl << "c. diesel" << endl;
        char ch;
        while(true)
        {
            cout << "==>";
            cin >> ch;
            if(ch=='a')
            {
                engineType->type = "oil";
                break;
            }
            else if(ch=='b')
            {
                engineType->type = "gas";
                break;
            }
            else if(ch=='c')
            {
                engineType->type = "diesel";
                break;
            }
            else cout << "Invalid input." << endl;
        }
        return engineType;
    }

    EnginePower* getEnginePower()
    {
        EnginePower* enginePower = new EnginePower();

        cout << endl;
        cout << "Engine Power (in kW - int): " << endl << "==>";
        int n; cin >> n;

        enginePower->power = n;
        return enginePower;
    }

    TireSize* getTireSize()
    {
        TireSize* tireSize = new TireSize();

        cout << endl;
        cout << "Tire Size (in mm - int): " << endl << "==>";
        int n; cin >> n;

        tireSize->size = n;
        return tireSize;
    }

    TurboCharger* getTurboCharger()
    {
        TurboCharger* turboCharger = new TurboCharger();
        turboCharger->turbo = 0;

        return turboCharger;
    }

    Weight* getWeight()
    {
        Weight* weight = new Weight();
        weight->weight = 0;

        return weight;
    }
};





class SportsVehicleBuilder : public Builder
{
public:
    ModelNumber* getModelNumber()
    {
        ModelNumber* modelNumber = new ModelNumber();

        system("cls");
        cout << "Enter the model number of the SPORTS vehicle (string): " << endl << "==>";
        string s; cin >> s;

        modelNumber->model = s;
        return modelNumber;
    }

    EngineType* getEngineType()
    {
        EngineType* engineType = new EngineType();
        engineType->type = "oil";

        return engineType;
    }

    EnginePower* getEnginePower()
    {
        EnginePower* enginePower = new EnginePower();

        cout << endl;
        cout << "Engine Power (in kW - int): " << endl << "==>";
        int n; cin >> n;

        enginePower->power = n;
        return enginePower;
    }

    TireSize* getTireSize()
    {
        TireSize* tireSize = new TireSize();

        cout << endl;
        cout << "Tire Size (in mm - int): " << endl << "==>";
        int n; cin >> n;

        tireSize->size = n;
        return tireSize;
    }

    TurboCharger* getTurboCharger()
    {
        TurboCharger* turboCharger = new TurboCharger();

        cout << endl;
        cout << "Turbo (int): " << endl << "==>";
        int n; cin >> n;

        turboCharger->turbo = n;
        return turboCharger;
    }

    Weight* getWeight()
    {
        Weight* weight = new Weight();
        weight->weight = 0;

        return weight;
    }
};





class HeavyVehicleBuilder : public Builder
{
public:
    ModelNumber* getModelNumber()
    {
        ModelNumber* modelNumber = new ModelNumber();

        system("cls");
        cout << "Enter the model number of the HEAVY vehicle (string): " << endl << "==>";
        string s; cin >> s;

        modelNumber->model = s;
        return modelNumber;
    }

    EngineType* getEngineType()
    {
        EngineType* engineType = new EngineType();
        engineType->type = "diesel";

        return engineType;
    }

    EnginePower* getEnginePower()
    {
        EnginePower* enginePower = new EnginePower();

        cout << endl;
        cout << "Engine Power (in kW - int): " << endl << "==>";
        int n; cin >> n;

        enginePower->power = n;
        return enginePower;
    }

    TireSize* getTireSize()
    {
        TireSize* tireSize = new TireSize();

        cout << endl;
        cout << "Tire Size (in mm - int): " << endl << "==>";
        int n; cin >> n;

        tireSize->size = n;
        return tireSize;
    }

    TurboCharger* getTurboCharger()
    {
        TurboCharger* turboCharger = new TurboCharger();
        turboCharger->turbo = 0;

        return turboCharger;
    }

    Weight* getWeight()
    {
        Weight* weight = new Weight();

        cout << endl;
        cout << "Weight (float): " << endl << "==>";
        float f; cin >> f;
        weight->weight = f;

        return weight;
    }
};





/* The Director object is responsible for the construction process of the complex object but delegates the actual creation and assembly to the Builder interface. */
class Director
{
    Builder* builder;

public:
    void setBuilder(Builder* newBuilder)
    {
        builder = newBuilder;
    }

    Vehicle* getVehicle()
    {
        Vehicle* vehicle = new Vehicle();

        vehicle->modelNumber = builder->getModelNumber();
        vehicle->engineType = builder->getEngineType();
        vehicle->enginePower = builder->getEnginePower();
        vehicle->tireSize = builder->getTireSize();
        vehicle->turboCharger = builder->getTurboCharger();
        vehicle->weight = builder->getWeight();

        return vehicle;
    }
};





int main()
{
    vector <Vehicle> v;
    vector <Vehicle>::iterator itr;

    Vehicle* vehicle;
    Director director;


    NormalVehicleBuilder normalVehicle;
    SportsVehicleBuilder sportsVehicle;
    HeavyVehicleBuilder heavyVehicle;

    int expected_visitor_count=30;

    while(true)
    {
        cout << "Chose an option from below-" << endl;
        cout << "1. Add a Vehicle" << endl;
        cout << "2. Remove a Vehicle" << endl;
        cout << "3. Show all Vehicles" << endl;
        cout << "0. Quit" << endl;

        while(true)
        {
            cout << "==>";
            char ch; cin >> ch;
            if(ch=='1')
            {
                system("cls");
                cout << "Select vehicle type-" << endl;
                cout << "1. Normal Vehicle" << endl;
                cout << "2. Sports Vehicle" << endl;
                cout << "3. Heavy Vehicle" << endl << "==>";

                bool flag=false;

                while(true)
                {
                    char c; cin >> c;
                    if(c=='1')
                    {
                        director.setBuilder(&normalVehicle);
                        vehicle = director.getVehicle();
                        v.push_back(*vehicle);
                        flag=true;
                        break;
                    }
                    else if(c=='2')
                    {
                        director.setBuilder(&sportsVehicle);
                        vehicle = director.getVehicle();
                        v.push_back(*vehicle);
                        expected_visitor_count += 20;
                        flag=true;
                        break;
                    }
                    else if(c=='3')
                    {
                        director.setBuilder(&heavyVehicle);
                        vehicle = director.getVehicle();
                        v.push_back(*vehicle);
                        flag=true;
                        break;
                    }
                    else cout << "Invalid input." << endl;
                }
                if(flag)
                {
                    system("cls");
                    cout << "Vehicle added!" << endl << endl;
                    break;
                }
            }
            else if(ch=='2')
            {
                system("cls");

                if(v.size() > 0)
                {
                    cout << "These are all the vehicles currently in the showroom." << endl;
                    for(int i=0; i < v.size(); i++)
                    {
                        cout << endl << "----- " << i+1 << " -----";
                        v[i].specifications();
                    }

                    cout << endl;
                    cout << "Enter the index number of the vehicle you want to remove." << endl << "==>";
                    int n; cin >> n;

                    if(v[n-1].turboCharger->turbo > 0) expected_visitor_count -= 20;

                    v.erase(v.begin()+n-1);

                    system("cls");
                    cout << "Vehicle removed!" << endl << endl;
                }
                else cout << "There are currently no vehicles in the showroom." << endl << endl;
                break;
            }
            else if(ch=='3')
            {
                system("cls");

                if(v.size() > 0)
                {
                    cout << "The vehicles that are currently listed in the showroom are: " << endl;
                    for(int i=0; i < v.size(); i++)
                    {
                        cout << endl << "----- " << i+1 << " -----";
                        v[i].specifications();
                    }
                    cout << endl;
                    cout << "==========================" << endl;
                    cout << "Expected visitor count: " << expected_visitor_count << endl;
                    cout << "==========================" << endl;
                }
                else cout << "There are currently no vehicles in the showroom.";

                cout << endl << endl;
                break;
            }
            else if(ch=='0') return 0;
            else cout << "Invalid input." << endl;
        }

    }
}
