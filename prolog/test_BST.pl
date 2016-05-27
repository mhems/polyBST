%% -*- Mode: Prolog; -*-

verify(A, A).
verify(Exp, Act) :- Exp \= Act,
                    format('expected ~p, received ~p~n', [Exp, Act]).

go :-
    T1 = empty,
    size(T1, S1), verify(0, S1),
    list(T1, L1), verify([], L1),
    add(T1, 5, T2),
    contains(T2, 5),
    size(T2, S2), verify(1, S2),
    list(T2, L2), verify([5], L2).
