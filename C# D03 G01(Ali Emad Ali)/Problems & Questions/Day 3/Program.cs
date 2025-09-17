using System;
using System.Text;

namespace Day_3
{
    class Btats
    {
        public int Value;
    }
    class Program
    {
        static void Main()
        {
            #region Problem 1
            // Console.Write("Enter a number: ");
            // string input = Console.ReadLine();

            // // Parse
            // try
            // {
            //     int number1 = int.Parse(input);
            //     Console.WriteLine($"int.Parse succeeded: {number1}");
            // }
            // catch (FormatException)
            // {
            //     Console.WriteLine("int.Parse failed: Input is not a valid integer.");
            // }
            // catch (OverflowException)
            // {
            //     Console.WriteLine("int.Parse failed: Number is too large or too small.");
            // }

            // // Convert
            // try
            // {
            //     int number2 = Convert.ToInt32(input);
            //     Console.WriteLine($"Convert.ToInt32 succeeded: {number2}");
            // }
            // catch (FormatException)
            // {
            //     Console.WriteLine("Convert.ToInt32 failed: Input is not a valid integer.");
            // }
            // catch (OverflowException)
            // {
            //     Console.WriteLine("Convert.ToInt32 failed: Number is too large or too small.");
            // }

            // Question: What is the difference between int.Parse and Convert.ToInt32 when handling null inputs?
            // Answer: int.Parse will throw an ArgumentNullException if the input is null,
            // while Convert.ToInt32 will return 0.
            #endregion

            #region Problem 2
            // Console.Write("Enter a number: ");
            // string input = Console.ReadLine();
            // if (int.TryParse(input, out int number))
            // {
            //     Console.WriteLine($"You entered: {number}");
            // }
            // else
            // {
            //     Console.WriteLine("Invalid input. Please enter a valid integer.");
            // }

            // Question: Why is TryParse recommended over Parse in user-facing applications?
            // Answer: TryParse is recommended because it does not throw exceptions for invalid input,
            // making it safer and more user-friendly. It allows for graceful handling of errors without crashing
            #endregion

            #region Problem 3
            // object obj;

            // obj = 42;
            // Console.WriteLine($"GetHashCode: {obj.GetHashCode()}");

            // obj = "Hello";
            // Console.WriteLine($"GetHashCode: {obj.GetHashCode()}");

            // obj = 3.1433;
            // Console.WriteLine($"GetHashCode: {obj.GetHashCode()}");

            // Question: Explain the real purpose of the GetHashCode() method.

            // Answer: The GetHashCode() method is used to generate a hash code for an object,
            // which is a numeric value that identifies the object's state. This is particularly
            // useful for using objects as keys in hash tables or dictionaries, as it allows for
            // quick lookups and comparisons.
            #endregion

            #region Problem 4
            // // Create an object and assign it a value
            // Btats obj1 = new Btats();
            // obj1.Value = 10;

            // // Create a second reference to the same object
            // Btats obj2 = obj1;

            // // Modify the value using one reference
            // obj1.Value = 20;

            // // Print the value using the other reference
            // Console.WriteLine($"Value from obj2: {obj2.Value}"); // Output: 20
            // // Question: What is the significance of reference equality in .NET?
            // // Answer: Reference equality in .NET means that two variables refer to the same object in memory.
            // // This is significant because it affects how changes to one variable are reflected in another.
            #endregion

            #region Problem 5
            // string message = "Hello, ";

            // Console.WriteLine($"GetHashCode before: {message.GetHashCode()}");

            // message += "Hi Ali";

            // Console.WriteLine($"GetHashCode after: {message.GetHashCode()}");

            // // Question: Why string is immutable in C# ?
            // // Answer: Strings are immutable in C# to ensure that they are thread-safe and to optimize memory usage.
            // // When a string is modified, a new string object is created, leaving the original unchanged.
            #endregion

            #region Problem 6
            // StringBuilder message = new StringBuilder("Hello, ");

            // Console.WriteLine($"GetHashCode before: {message.GetHashCode()}");

            // message.Append("Hi Ali");

            // Console.WriteLine($"GetHashCode after: {message.GetHashCode()}");

            // // Question: How does StringBuilder address the inefficiencies of string concatenation?
            // // Answer: StringBuilder addresses the inefficiencies of string concatenation by using a mutable buffer
            // // to store the string data. This allows for modifications without creating new string objects,
            // // reducing memory overhead and improving performance, especially in scenarios with frequent changes.
            #endregion

            #region Question
            // Question: Why is StringBuilder faster for large-scale string modifications?
            // Answer: StringBuilder is faster for large-scale string modifications because it maintains a mutable buffer
            // that can grow as needed, avoiding the overhead of creating new string objects for each modification.
            #endregion

            #region Problem 7
            // Console.Write("Enter the first integer: ");
            // string? input1 = Console.ReadLine();
            // Console.Write("Enter the second integer: ");
            // string? input2 = Console.ReadLine();

            // if (int.TryParse(input1, out int num1) && int.TryParse(input2, out int num2))
            // {
            //     int sum = num1 + num2;

            //     // Concatenation
            //     Console.WriteLine("Sum is " + num1 + "+" + num2 + "=" + sum);

            //     // Composite formatting
            //     Console.WriteLine(string.Format("Sum is {0}+{1}={2}", num1, num2, sum));

            //     // String interpolation
            //     Console.WriteLine($"Sum is {num1}+{num2}={sum}");
            // }
            // else
            // {
            //     Console.WriteLine("Invalid input. Please enter valid integers.");
            // }

            // // Question: Which string formatting method is most used and why?
            // // Answer: String interpolation is often the most used method because it is concise, readable,
            // // and allows for easy inclusion of variables directly within the string. It improves code clarity.
            #endregion

            #region Problem 8
            // StringBuilder sb = new StringBuilder("Hello, World!");

            // // Append
            // sb.Append(" Welcome to Shawrma.");

            // // Replace
            // sb.Replace("World", "Ali");

            // // Insert
            // sb.Insert(0, "Greetings, ");

            // // Remove
            // sb.Remove(9, 7); // Removes "Hello,"

            // Console.WriteLine(sb.ToString());

            // // Question: Explain how StringBuilder is designed to handle frequent modifications compared to strings.
            // // Answer: StringBuilder is designed to handle frequent modifications by using a mutable buffer that can grow as needed.
            // // This avoids the overhead of creating new string objects for each modification, making it more efficient for scenarios
            // // with many changes. In contrast, strings are immutable, so any modification results in the creation of a new string,
            // // which can lead to increased memory usage and reduced performance.
            #endregion
        }
    }
}