using System;
using System.Text;

/// <summary>
/// ThIs Is An ExAmPlE oF mIxEd CaSe WoRdS
/// </summary>
internal class MixedCaseLetters
{
    private static void MixCase(string text = "dEfAuLt")
    {
        if (string.IsNullOrWhiteSpace(text))
            return;

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < text.Length; i++)
        {
            if (char.ToUpper(text[i]) == text[i])
                sb.Append(char.ToLower(text[i]));

            else if (char.ToLower(text[i]) == text[i])
                sb.Append(char.ToUpper(text[i]));
        }

        Console.WriteLine($"Original Text: {text}\n" +
                          $"Converted Text: {sb}");
    }
}
