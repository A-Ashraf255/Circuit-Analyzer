#include <iostream>
using namespace std;

double total_resistance(const string &description, char connection);
bool is_not_valid(string description);

int main()
{
   string description;
   double Req = 0, voltage;

   cout << "Circuit description: ";
   getline(cin, description);

   cout << "Applied voltage: ";
   cin >> voltage;

   if (is_not_valid(description))
      cout << "Invalid circuit description";
   else
   {
      char parent_connection = description[0];
      Req = total_resistance(description, parent_connection);
      cout << "Total resistance = " << Req << " ohm\n";
      cout << "Circuit current = " << voltage / Req << " A";
   }
}

// Calculate the total resistance for the given branch, the function handle all types of mixed connections.
double total_resistance(const string &description, char connection)
{
   double Req = 0, R_temp;
   string value; // hold resistance value digits to be passed to stod() function
   // 'i' is a static variable that is responsible for memorizing the last iteration index before calling total_resistance recursively
   static int i = 2;
   // For each recursive call, the function should return Req when it reaches the end of child connection 'e' or the end of parent connection 'E'.
   while (description[i] != 'e' && description[i] != 'E')
   {
      // If a branch is found, call total_resistance function recursively.
      // Since the variable 'i' is static, the function will continue from the last index it was pointing at.
      if (description[i] == 'S' || description[i] == 'P')
      {
         char branch_connection = description[i++]; // incrementing i by 1 to avoid infinite recursion calls.
         R_temp = total_resistance(description, branch_connection);
         Req += connection == 'S' ? R_temp : 1 / R_temp;
      }
      else
      {
         // This loop extracts the resistance digits from the circuit description string.
         while (isdigit(description[i]) || description[i] == '.')
            value += description[i++];
         // Check if 'value' is empty or not before passing it to stod() to avoid any exception.
         if (!value.empty())
         {
            R_temp = stod(value);
            Req += connection == 'S' ? R_temp : 1 / R_temp;
         }
         // Initialize 'value' for the next resistance value.
         value = "";
      }
      i++;
   }
   // Return the total resistance based on the connection type.
   return connection == 'S' ? Req : 1 / Req;
}

// Check if the circuit description contains invalid characters.
bool is_not_valid(string description)
{
   bool notValid = false;
   for (auto &character : description)
   {
      // Checking if the user entered non-allowed characters.
      switch (character)
      {
      case '.':
      case ' ':
      case '0' ... '9':
      case 'e':
      case 'E':
      case 'P':
      case 'S':
         break;
      default:
         notValid = true;
      }
   }
   return notValid;
}
