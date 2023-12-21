% Universidad de La Laguna
% Escuela Superior de Ingeniería y Tecnología
% Grado en Ingeniería Informática
% Asignatura: Inteligencia Artificial
% Curso: 3º
% Práctica 4: Proyecto individual de Prolog
% Autor: Alejandro M.L (alu0101443126@ull.edu.es)
% Fecha: 18/12/2023

% Hechos

% Hechos para Pokémon de primera generación
pokemon(bulbasaur).
pokemon(ivysaur).
pokemon(venusaur).
pokemon(charmander).
pokemon(charmeleon).
pokemon(charizard).
pokemon(squirtle).
pokemon(wartortle).
pokemon(blastoise).
pokemon(caterpie).
pokemon(metapod).
pokemon(butterfree).
pokemon(weedle).
pokemon(kakuna).
pokemon(beedrill).
pokemon(pidgey).
pokemon(pidgeotto).
pokemon(pidgeot).
pokemon(rattata).
pokemon(raticate).
pokemon(spearow).
pokemon(fearow).
pokemon(ekans).
pokemon(arbok).
pokemon(pikachu).
pokemon(raichu).
pokemon(sandshrew).
pokemon(sandslash).
pokemon(nidoran_f).
pokemon(nidorina).
pokemon(nidoqueen).
pokemon(nidoran_m).
pokemon(nidorino).
pokemon(nidoking).
pokemon(clefairy).
pokemon(clefable).
pokemon(vulpix).
pokemon(ninetales).
pokemon(jigglypuff).
pokemon(wigglytuff).
pokemon(zubat).
pokemon(golbat).
pokemon(oddish).
pokemon(gloom).
pokemon(vileplume).
pokemon(paras).
pokemon(parasect).
pokemon(venonat).
pokemon(venomoth).
pokemon(diglett).
pokemon(dugtrio).


% Hechos para Tipos de Pokémon

tipo(bulbasaur, planta).
tipo(bulbasaur, veneno).
tipo(ivysaur, planta).
tipo(ivysaur, veneno).
tipo(venusaur, planta).
tipo(venusaur, veneno).
tipo(charmander, fuego).
tipo(charmeleon, fuego).
tipo(charizard, fuego).
tipo(charizard, volador).
tipo(squirtle, agua).
tipo(wartortle, agua).
tipo(blastoise, agua).
tipo(caterpie, bicho).
tipo(metapod, bicho).
tipo(butterfree, bicho).
tipo(butterfree, volador).
tipo(weedle, bicho).
tipo(weedle, veneno).
tipo(kakuna, bicho).
tipo(kakuna, veneno).
tipo(beedrill, bicho).
tipo(beedrill, veneno).
tipo(pidgey, normal).
tipo(pidgey, volador).
tipo(pidgeotto, normal).
tipo(pidgeotto, volador).
tipo(pidgeot, normal).
tipo(pidgeot, volador).
tipo(rattata, normal).
tipo(raticate, normal).
tipo(spearow, normal).
tipo(spearow, volador).
tipo(fearow, normal).
tipo(fearow, volador).
tipo(ekans, veneno).
tipo(arbok, veneno).
tipo(pikachu, eléctrico).
tipo(raichu, eléctrico).
tipo(sandshrew, tierra).
tipo(sandslash, tierra).
tipo(nidoran_f, veneno).
tipo(nidorina, veneno).
tipo(nidoqueen, veneno).
tipo(nidoqueen, tierra).
tipo(nidoran_m, veneno).
tipo(nidorino, veneno).
tipo(nidoking, veneno).
tipo(nidoking, tierra).
tipo(clefairy, normal).
tipo(clefable, normal).
tipo(vulpix, fuego).
tipo(ninetales, fuego).
tipo(jigglypuff, normal).
tipo(wigglytuff, normal).
tipo(zubat, veneno).
tipo(zubat, volador).
tipo(golbat, veneno).
tipo(golbat, volador).
tipo(oddish, planta).
tipo(oddish, veneno).
tipo(gloom, planta).
tipo(gloom, veneno).
tipo(vileplume, planta).
tipo(vileplume, veneno).
tipo(paras, bicho).
tipo(paras, planta).
tipo(parasect, bicho).
tipo(parasect, planta).
tipo(venonat, bicho).
tipo(venonat, veneno).
tipo(venomoth, bicho).
tipo(venomoth, veneno).
tipo(diglett, tierra).
tipo(dugtrio, tierra).

% TABLA DE TIPOS

% Relaciones de Eficacia
eficaz(acero, roca).
eficaz(acero, hielo).
eficaz(agua, fuego).
eficaz(agua, roca).
eficaz(agua, tierra).
eficaz(bicho, planta).
eficaz(bicho, psiquico).
eficaz(bicho, siniestro).
eficaz(dragón, dragón).
eficaz(electrico, agua).
eficaz(electrico, volador).
eficaz(fantasma, fantasma).
eficaz(fantasma, volador).
eficaz(fuego, bicho).
eficaz(fuego, planta).
eficaz(fuego, hielo).
eficaz(fuegio, acero).
eficaz(hielo, dragon).
eficaz(hielo, planta).
eficaz(hielo, tierra).
eficaz(hielo, volador).
eficaz(lucha, normal).
eficaz(planta, agua).
eficaz(planta, tierra).
eficaz(planta, roca).
eficaz(psiquico, lucha).
eficaz(psiquico, veneno).
eficaz(roca, bicho).
eficaz(roca, fuego).
eficaz(roca, hielo).
eficaz(roca, volador).
eficaz(siniestro, fantasma).
eficaz(siniestro, psiquico).
eficaz(tierra, acero).
eficaz(tierra, fuego).
eficaz(tierra, roca).
eficaz(tierra, veneno). 
eficaz(tierra, electrico).
eficaz(veneno, planta).
eficaz(volador, bicho).
eficaz(volador, planta).
eficaz(volador, lucha).

% Relaciones de No Eficacia (Ineficacia)
debil(acero, agua).
debil(acero, eléctrico).
debil(acero, fuego).
debil(acero, acero).
debil(agua, agua).
debil(agua, planta).
debil(agua, dragón).
debil(bicho, fuego).
debil(bicho, acero).
debil(bicho, veneno).
debil(bicho, volador).
debil(bicho, fantasma).
debil(dragón, acero).
debil(electrico, tierra).
debil(electrico, planta).
debil(electrico, dragón).
debil(electrico, electrico).
debil(fantasma, normal).
debil(fantasma, siniestro).
debil(fuego, roca).
debil(fuego, fuego).
debil(fuego, dragón).
debil(fuego, agua).
debil(hielo, fuego).
debil(hielo, agua).
debil(hielo, hielo).
debil(hielo, acero).
debil(lucha, veneno).
debil(lucha, volador).
debil(lucha, psiquico).
debil(lucha, fantasma).
debil(lucha, bicho).
debil(normal, roca).
debil(normal, acero).
debil(normal, fantasma).
debil(planta, veneno).
debil(planta, fuego).
debil(planta, dragón).
debil(planta, volador).
debil(planta, acero).
debil(planta, bicho).
debil(psiquico, acero).
debil(psiquico, psiquico).
debil(psiquico, siniestro).
debil(roca, lucha).
debil(roca, tierra).
debil(roca, acero).
debil(siniestro, lucha).
debil(siniestro, siniestro).
debil(tierra, planta).
debil(tierra, bicho).
debil(tierra, volador).
debil(veneno, roca).
debil(veneno, fantasma).
debil(veneno, acero).
debil(veneno, tierra).
debil(veneno, veneno).
debil(volador, roca).
debil(volador, acero).
debil(volador, eléctrico).

% Relaciones de Inmunidad
inmune(normal, fantasma).
inmune(fantasma, normal).
inmune(fantasma, lucha).
inmune(acero, veneno).
inmune(lucha, fantasma).
inmune(psiquico, siniestro).
inmune(tierra, eléctrico).
inmune(volador, tierra).

% Reglas de consulta

% Regla para obtener los tipos de un Pokémon
tipos_de_pokemon(Pokemon, Tipos) :-
    findall(Tipo, tipo(Pokemon, Tipo), Tipos).

% Regla para determinar si un Pokémon es eficaz contra otro
es_eficaz_contra(PokemonAtacante, PokemonDefensor) :-
    tipos_de_pokemon(PokemonAtacante, TiposAtacante),
    tipos_de_pokemon(PokemonDefensor, TiposDefensor),
    member(TipoAtacante, TiposAtacante),
    member(TipoDefensor, TiposDefensor),
    eficaz(TipoAtacante, TipoDefensor).

% Regla para determinar si un Pokémon es débil contra otro
es_debil_contra(PokemonAtacante, PokemonDefensor) :-
    tipos_de_pokemon(PokemonAtacante, TiposAtacante),
    tipos_de_pokemon(PokemonDefensor, TiposDefensor),
    member(TipoAtacante, TiposAtacante),
    member(TipoDefensor, TiposDefensor),
    debil(TipoAtacante, TipoDefensor).

% Regla para determinar si un Pokémon es inmune contra otro
es_inmune_contra(PokemonAtacante, PokemonDefensor) :-
    tipos_de_pokemon(PokemonAtacante, TiposAtacante),
    tipos_de_pokemon(PokemonDefensor, TiposDefensor),
    member(TipoAtacante, TiposAtacante),
    member(TipoDefensor, TiposDefensor),
    inmune(TipoAtacante, TipoDefensor).

% Regla para determinar la eficacia global de un Pokémon contra otro
eficacia_global(PokemonAtacante, PokemonDefensor, Eficacia) :-
    tipos_de_pokemon(PokemonAtacante, TiposAtacante),
    tipos_de_pokemon(PokemonDefensor, TiposDefensor),
    findall(E, (
        member(TipoAtacante, TiposAtacante),
        member(TipoDefensor, TiposDefensor),
        (eficaz(TipoAtacante, TipoDefensor) -> E = 2 ; E = 1)
    ), Eficacias),
    prod_lista(Eficacias, Eficacia).

% Regla para calcular el producto de los elementos de una lista
prod_lista([], 1).
prod_lista([X|Xs], Prod) :-
    prod_lista(Xs, Resto),
    Prod is X * Resto.

% Regla para recomendar Pokémon basados en preferencias de tipo
recomendar_pokemon_preferencias(TipoPreferido, Recomendacion) :-
    findall(Pokemon, (
        pokemon(Pokemon),
        tipos_de_pokemon(Pokemon, Tipos),
        (member(TipoPreferido, Tipos) ->
            true
            ;
            tipos_eficaces_contra(TipoPreferido, Tipos, TiposEficaces),
            member(Pokemon, TiposEficaces)
        )
    ), ListaRecomendaciones),
    length(ListaRecomendaciones, Longitud),
    Longitud > 0,
    random_member(Recomendacion, ListaRecomendaciones).

% Regla para obtener tipos eficaces contra un tipo dado
tipos_eficaces_contra(Tipo, TiposOriginales, TiposEficaces) :-
    findall(TipoEficaz, (
        eficaz(Tipo, TipoEficaz),
        member(TipoEficaz, TiposOriginales)
    ), TiposEficaces).

% Menú de selección de opciones
menu :-
    write('1. Consultar tipos de un Pokémon'), nl,
    write('2. Determinar si un Pokémon es eficaz contra otro'), nl,
    write('3. Determinar si un Pokémon es débil contra otro'), nl,
    write('4. Determinar si un Pokémon es inmune contra otro'), nl,
    write('5. Calcular eficacia global de un Pokémon contra otro'), nl,
    write('6. Recomendar Pokémon basado en preferencias de tipo'), nl,
    write('7. Salir'), nl,
    write('Ingrese el número de la opción deseada: '),
    read(Opcion),
    ejecutar_opcion(Opcion).

% Regla para ejecutar la opción seleccionada
ejecutar_opcion(1) :-
    write('Ingrese el nombre del Pokémon: '),
    read(Pokemon),
    tipos_de_pokemon(Pokemon, Tipos),
    write('Tipos de '), write(Pokemon), write(': '), write(Tipos), nl,
    menu.

ejecutar_opcion(2) :-
    write('Ingrese el nombre del Pokémon atacante: '),
    read(Atacante),
    write('Ingrese el nombre del Pokémon defensor: '),
    read(Defensor),
    (es_eficaz_contra(Atacante, Defensor) ->
        write(Atacante), write(' es eficaz contra '), write(Defensor), nl;
        write(Atacante), write(' no es eficaz contra '), write(Defensor), nl),
    menu.

ejecutar_opcion(3) :-
    write('Ingrese el nombre del Pokémon atacante: '),
    read(Atacante),
    write('Ingrese el nombre del Pokémon defensor: '),
    read(Defensor),
    (es_debil_contra(Atacante, Defensor) ->
        write(Atacante), write(' es débil contra '), write(Defensor), nl;
        write(Atacante), write(' no es débil contra '), write(Defensor), nl),
    menu.

ejecutar_opcion(4) :-
    write('Ingrese el nombre del Pokémon atacante: '),
    read(Atacante),
    write('Ingrese el nombre del Pokémon defensor: '),
    read(Defensor),
    (es_inmune_contra(Atacante, Defensor) ->
        write(Atacante), write(' es inmune contra '), write(Defensor), nl;
        write(Atacante), write(' no es inmune contra '), write(Defensor), nl),
    menu.

ejecutar_opcion(5) :-
    write('Ingrese el nombre del Pokémon atacante: '),
    read(Atacante),
    write('Ingrese el nombre del Pokémon defensor: '),
    read(Defensor),
    eficacia_global(Atacante, Defensor, Eficacia),
    write('Eficacia global de '), write(Atacante), write(' contra '), write(Defensor),
    write(': '), write(Eficacia), nl,
    menu.

% Nueva regla para la opción 6
ejecutar_opcion(6) :-
    write('Ingrese su tipo de Pokémon preferido: '),
    read(TipoPreferido),
    recomendar_pokemon_preferencias(TipoPreferido, Recomendacion),
    write('Se recomienda el Pokémon: '), write(Recomendacion), nl,
    menu.

ejecutar_opcion(7) :- write('¡Hasta luego!'), nl.

ejecutar_opcion(_) :- write('Opción no válida. Inténtelo de nuevo.'), nl, menu.

% Iniciar el programa llamando a la regla del menú
:- menu.