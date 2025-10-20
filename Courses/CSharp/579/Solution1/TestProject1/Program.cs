using System;



namespace MyNamespace
{
    
    
    // Inside the Namespace
    public class Person
    {
        public required string LastName { get; set; }
        public required string FirstName { get; set; }
    }
    public record OtherPerson(string FirstName, string LastName);
    public record OtherPersonWithPhone(string FirstName, string LastName, string[] PhoneNumbers);
    public record OtherPersonWithPhoneAndRequiredArray(string FirstName, string LastName)
    {
        public required string[] PhoneNumbers { get; init; }
    }

    public static class Program
    {
        static int QuestionMarks() 
        {
            string? s = Console.ReadLine(); // '?' means can be NULL
            int returnValue = int.Parse(s ?? "-1"); // "??" means IF IS NULL
            return returnValue;
        }
        public static void Main(string [] args)
        {

            Console.WriteLine("Hello World!");

            try
            {
                Console.Write("Please enter a number: ");
                var x = QuestionMarks();
                Console.WriteLine($"Printing... -> {x}");
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }

            

            {
                int a = 5;
                int b = a + 2; //OK
                bool test = true;
                // Error. Operator '+' cannot be applied to operands of type 'int' and 'bool'.
                //int c = a + test;
            }

            {
                // var p1 = new Person(); // Error! Required properties not set
                //Console.WriteLine(p1.FirstName + " " + p1.LastName);
                var p2 = new Person() { FirstName = "Grace", LastName = "Hopper" };
                Console.WriteLine(p2.FirstName + " " + p2.LastName);
            }
            
            OtherPerson o_person = new("Nancy", "Davolio");
            Console.WriteLine(o_person);
            // output: Person { FirstName = Nancy, LastName = Davolio }

            {
                var phoneNumbers = new string[2];
                OtherPersonWithPhone person1 = new("Nancy", "Davolio", phoneNumbers);
                OtherPersonWithPhone person2 = new("Nancy", "Davolio", phoneNumbers);
                Console.WriteLine(person1 == person2); // output: True

                person1.PhoneNumbers[0] = "555-1234";
                Console.WriteLine(person1 == person2); // output: True

                Console.WriteLine(ReferenceEquals(person1, person2)); // output: False
            }




            //OtherPersonWithPhoneAndRequiredArray
            {

                Console.WriteLine("\n");
                
                OtherPersonWithPhoneAndRequiredArray person1 = new("Nancy", "Davolio") { PhoneNumbers = new string[1] };
                Console.WriteLine(person1);
                // output: Person { FirstName = Nancy, LastName = Davolio, PhoneNumbers = System.String[] }

                OtherPersonWithPhoneAndRequiredArray person2 = person1 with { FirstName = "John" };
                Console.WriteLine(person2);
                // output: Person { FirstName = John, LastName = Davolio, PhoneNumbers = System.String[] }
                Console.WriteLine(person1 == person2); // output: False

                person2 = person1 with { PhoneNumbers = new string[1] };
                Console.WriteLine(person2);
                // output: Person { FirstName = Nancy, LastName = Davolio, PhoneNumbers = System.String[] }
                Console.WriteLine(person1 == person2); // output: False

                person2 = person1 with { };
                Console.WriteLine(person1 == person2); // output: True
                
                
            }

        
           

        
        }
    }
}




