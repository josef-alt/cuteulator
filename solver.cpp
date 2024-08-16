#include<vector>
#include<string>
#include<stack>
#include<stdexcept>

const long double PI = 3.14159265L;
const long double E  = 2.71828182L;

int priority(std::string term)
{
    if(term == "(")
    {
        return 2;
    }
    else if(term == ")")
    {
        return 3;
    }
    else if(term == "*")
    {
        return 4;
    }
    else if(term == "/")
    {
        return 5;
    }
    else if(term == "+")
    {
        return 6;
    }
    else if(term == "-")
    {
        return 7;
    }
    else
    {
        return 0;
    }
}

long double evaluate(long double term1, int op, long double term2)
{
    switch(op)
    {
    case 4:
        return term1 * term2;
    case 5:
        return term1 / term2;
    case 6:
        return term1 + term2;
    case 7:
        return term1 - term2;
    }
}

// this is just a basic implementation of dijkstra's two-stack algorithm
long double solve(std::vector<std::string> expression)
{
    std::stack<int> operators;
    std::stack<long double> values;

    for(std::string term : expression)
    {
        int precedence = priority(term);

        // operands
        if(precedence == 0)
        {
            try
            {
                if(term == "π")
                {
                    values.push(PI);
                }
                else if(term == "e")
                {
                    values.push(E);
                }
                else
                {
                    values.push(stold(term));
                }
            }
            catch(const std::invalid_argument& ex)
            {
                // something really went wrong here
                throw ex;
            }
            catch(const std::out_of_range& ex)
            {
                throw std::out_of_range("ERROR: OVERFLOW");
            }
        }
        // open
        else if(precedence == 2)
        {
            operators.push(precedence);
        }
        // close
        else if(precedence == 3)
        {
            while(!operators.empty() && operators.top() != 2)
            {
                long double term2 = values.top();
                values.pop();
                long double term1 = values.top();
                values.pop();
                long double res = evaluate(term1, operators.top(), term2);

                operators.pop();

                values.push(res);
            }
            operators.pop();
        }
        // add sub mult div
        else if(precedence > 3 && precedence < 8)
        {
            while(!operators.empty() && operators.top() != 2 && operators.top() / 2 <= precedence / 2)
            {
                long double term2 = values.top();
                values.pop();
                long double term1 = values.top();
                values.pop();

                long double res = evaluate(term1, operators.top(), term2);
                operators.pop();

                values.push(res);
            }
            operators.push(precedence);
        }
    }

    // handle all left over operations
    while(!operators.empty())
    {
        long double term2 = values.top();
        values.pop();
        long double term1 = values.top();
        values.pop();
        long double res = evaluate(term1, operators.top(), term2);
        operators.pop();

        values.push(res);
    }

    return values.top();
}
