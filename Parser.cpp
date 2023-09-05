#include "Parser.hpp"  
#include "TokenType.hpp" 
#include <list>  
#include "NumberExpression.cpp" 
#include "BinaryExpression.cpp" 
#include "UnaryExpression.cpp"
#include "VariableExpression.cpp"
#include <iostream> 
#include "Statement.hpp"
#include "PrintStatement.cpp"
using namespace ast;
using namespace std;

namespace Parsing {

    list<Statement*> Parser::parse() {
        list<Statement*> result;

        //начало поиска операторов
        while (!match(TokenType::FILEEND)) {
            result.push_back(statement());
        }

        return result;
    }

    Statement* Parser::statement() {
        if (match(TokenType::PRINT))
            return new PrintStatement(expression());
        return assigmentStatement();
    }
    Statement* Parser::assigmentStatement() {
        Token current = get(0);

        if (match(TokenType::WORD) &&
            get(0).getType() == TokenType::SET) {
            const string variable = current.getText();
            consume(TokenType::SET);
            return new AssignmentStatement(variable, expression());
        }
        else {
            cerr << "Uniknown statement" << endl;
            exit(0);
        }
    }


    Expression* Parser::expression() {
        return additive();
    }
    Expression* Parser::additive() {
        Expression* result = multiplicative();

        while (true) {
            if (match(TokenType::PLUS)) {
                result = new BinaryExpression('+', result, multiplicative());
                continue;
            }
            else if (match(TokenType::MINUS)) {
                result = new BinaryExpression('-', result, multiplicative());
                continue;
            }
            break;
        }

        return result;
    }
    Expression* Parser::multiplicative() {
        Expression* result = unary();

        while (true) {
            if (match(TokenType::STAR)) {
                result = new BinaryExpression('*', result, unary());
                continue;
            }
            else if (match(TokenType::SLASH)) {
                result = new BinaryExpression('/', result, unary());
                continue;
            }
            break;
        }

        return result;
    }
    Expression* Parser::unary() {
        if (match(TokenType::MINUS)) {
            return new UnaryExpression('-', primary());
        }
        else if (match(TokenType::PLUS)) {
            return primary();
        }
        return primary();
    }
    Expression* Parser::primary() {
        Token current = get(0);
        if (match(TokenType::NUMBER)) {
            return new NumberExpression(stod(current.getText()));
        }
        else if (match(TokenType::WORD)) {
            return new VariableExpression(current.getText());
        }
        else if (match(TokenType::LPAREN)) {
            Expression* result = expression();
            match(TokenType::RPAREN);
            return result;
        }
        cerr << "Unknown expression" << endl;
        return NULL;
    }

    bool Parser::consume(TokenType type) {
        Token current = get(0);
        if (type != current.getType()) {
            cerr << "Token N" + to_string(static_cast<int>(current.getType())) +
                " doesn't match N" + to_string(static_cast<int>(type));
            exit(0);
        }
        pos++;
        return true;
    }
    bool Parser::match(TokenType type) {
        Token current = get(0);
        if (type != current.getType()) return false;
        pos++;
        return true;
    }

    Token Parser::get(int relativePosition) {
        const int position = pos + relativePosition;
        if (position >= size) return FILEEND;
        auto it = tokens.begin();
        std::advance(it, position);
        return *it;
    }
}