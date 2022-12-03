class Solution
{
public:
    bool checkIfPangram(string sentence)
    {

        // or put all elements in set as no repeatition so size =26
        if (sentence.size() < 26)
            return false;

        // working with ascii character as lowercase 97 to 122
        sort(sentence.begin(), sentence.end());
        char c = 97; // ascii to char conv done
        for (int i = 0; i < sentence.length() && c <= 122; i++)
        {
            if (c == sentence[i])
            {
                c++;
            }
            else if (c < sentence[i]) // if value repeat ignore
                break;
        }

        if (c != 123)
            return false; // if not reached till z
        return true;
    }
};