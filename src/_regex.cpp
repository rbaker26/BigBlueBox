#include "_regex.h"

_Regex::_Regex()
{

}

bool _Regex::isItemName(QString s)
{
    QRegularExpression rx("^[A-Za-z0-9().-_]{1}[A-Za-z0-9() .-_]{0,25}$");
    QRegularExpressionMatch match = rx.match(s);
    return match.hasMatch();
}
