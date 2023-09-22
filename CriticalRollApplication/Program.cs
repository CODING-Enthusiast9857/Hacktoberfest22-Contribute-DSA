namespace CriticalRollApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Random dice = new Random();
            DiceRolls(dice);
        }
        public static List<int> DiceRolls(Random dice)
        {
            var diceRolls = new List<int>();
            var count = 1;
            var previousRoll = 0;
            // Rolls a dice a total of 10 times
            for (var i = 0; i < 10; i++)
            {
                int roll;
                do
                {
                    roll = dice.Next(1, 21);

                    if (roll == 1)
                    {
                        Console.WriteLine($"{count++}. {roll} = critical failure");
                    }
                    else if (roll == 20)
                    {
                        Console.WriteLine($"{count++}. {roll} = critical success");
                    }
                    else
                    {
                        Console.WriteLine($"{count++}. {roll}");
                    }
                } while (roll == previousRoll); // Makes sure that the previous roll is not the same as the next roll.
                previousRoll = roll;
                diceRolls.Add(roll);
            }
            diceRolls.Sort(); // Sort dice rolls from lowest to highest
            return diceRolls;
        }
    }
}