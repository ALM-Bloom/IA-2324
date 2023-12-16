% Práctica "Proyecto Prolog"
% "Pokédex Avanzada en Prolog"
% Inteligencia Artificial 2023/2024
% Autor: Alejandro M.L

% Hechos
% Definición de Pokémon de primera generación

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
pokemon(meowth).
pokemon(persian).
pokemon(psyduck).
pokemon(golduck).
pokemon(mankey).
pokemon(primeape).
pokemon(growlithe).
pokemon(arcanine).
pokemon(poliwag).
pokemon(poliwhirl).
pokemon(poliwrath).
pokemon(abra).
pokemon(kadabra).
pokemon(alakazam).
pokemon(machop).
pokemon(machoke).
pokemon(machamp).
pokemon(bellsprout).
pokemon(weepinbell).
pokemon(victreebel).
pokemon(tentacool).
pokemon(tentacruel).
pokemon(geodude).
pokemon(graveler).
pokemon(golem).
pokemon(ponyta).
pokemon(rapidash).
pokemon(slowpoke).
pokemon(slowbro).
pokemon(magnemite).
pokemon(magneton).
pokemon(farfetchd).
pokemon(doduo).
pokemon(dodrio).
pokemon(seel).
pokemon(dewgong).
pokemon(grimer).
pokemon(muk).
pokemon(shellder).
pokemon(cloyster).
pokemon(gastly).
pokemon(haunter).
pokemon(gengar).
pokemon(onix).
pokemon(drowzee).
pokemon(hypno).
pokemon(krabby).
pokemon(kingler).
pokemon(voltorb).
pokemon(electrode).
pokemon(exeggcute).
pokemon(exeggutor).
pokemon(cubone).
pokemon(marowak).
pokemon(hitmonlee).
pokemon(hitmonchan).
pokemon(lickitung).
pokemon(koffing).
pokemon(weezing).
pokemon(rhyhorn).
pokemon(rhydon).
pokemon(chansey).
pokemon(tangela).
pokemon(kangaskhan).
pokemon(horsea).
pokemon(seadra).
pokemon(goldeen).
pokemon(seaking).
pokemon(staryu).
pokemon(starmie).
pokemon(mr_mime).
pokemon(scyther).
pokemon(jynx).
pokemon(electabuzz).
pokemon(magmar).
pokemon(pinsir).
pokemon(tauros).
pokemon(magikarp).
pokemon(gyarados).
pokemon(lapras).
pokemon(ditto).
pokemon(eevee).
pokemon(vaporeon).
pokemon(jolteon).
pokemon(flareon).
pokemon(porygon).
pokemon(omanyte).
pokemon(omastar).
pokemon(kabuto).
pokemon(kabutops).
pokemon(aerodactyl).
pokemon(snorlax).
pokemon(articuno).
pokemon(zapdos).
pokemon(moltres).
pokemon(dratini).
pokemon(dragonair).
pokemon(dragonite).
pokemon(mewtwo).
pokemon(mew).


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
tipo(meowth, normal).
tipo(persian, normal).
tipo(psyduck, agua).
tipo(golduck, agua).
tipo(mankey, lucha).
tipo(primeape, lucha).
tipo(growlithe, fuego).
tipo(arcanine, fuego).
tipo(poliwag, agua).
tipo(poliwhirl, agua).
tipo(poliwrath, agua).
tipo(poliwrath, lucha).
tipo(abra, psíquico).
tipo(kadabra, psíquico).
tipo(alakazam, psíquico).
tipo(machop, lucha).
tipo(machoke, lucha).
tipo(machamp, lucha).
tipo(bellsprout, planta).
tipo(bellsprout, veneno).
tipo(weepinbell, planta).
tipo(weepinbell, veneno).
tipo(victreebel, planta).
tipo(victreebel, veneno).
tipo(tentacool, agua).
tipo(tentacool, veneno).
tipo(tentacruel, agua).
tipo(tentacruel, veneno).
tipo(geodude, roca).
tipo(geodude, tierra).
tipo(graveler, roca).
tipo(graveler, tierra).
tipo(golem, roca).
tipo(golem, tierra).
tipo(ponyta, fuego).
tipo(rapidash, fuego).
tipo(slowpoke, agua).
tipo(slowpoke, psíquico).
tipo(slowbro, agua).
tipo(slowbro, psíquico).
tipo(magnemite, eléctrico).
tipo(magnemite, acero).
tipo(magneton, eléctrico).
tipo(magneton, acero).
tipo(farfetchd, normal).
tipo(farfetchd, volador).
tipo(doduo, normal).
tipo(doduo, volador).
tipo(dodrio, normal).
tipo(dodrio, volador).
tipo(seel, agua).
tipo(dewgong, agua).
tipo(dewgong, hielo).
tipo(grimer, veneno).
tipo(muk, veneno).
tipo(shellder, agua).
tipo(cloyster, agua).
tipo(cloyster, hielo).
tipo(gastly, fantasma).
tipo(gastly, veneno).
tipo(haunter, fantasma).
tipo(haunter, veneno).
tipo(gengar, fantasma).
tipo(gengar, veneno).
tipo(onix, roca).
tipo(onix, tierra).
tipo(drowzee, psíquico).
tipo(hypno, psíquico).
tipo(krabby, agua).
tipo(kingler, agua).
tipo(voltorb, eléctrico).
tipo(electrode, eléctrico).
tipo(exeggcute, planta).
tipo(exeggcute, psíquico).
tipo(exeggutor, planta).
tipo(exeggutor, psíquico).
tipo(cubone, tierra).
tipo(marowak, tierra).
tipo(hitmonlee, lucha).
tipo(hitmonchan, lucha).
tipo(lickitung, normal).
tipo(koffing, veneno).
tipo(weezing, veneno).
tipo(rhyhorn, tierra).
tipo(rhyhorn, roca).
tipo(rhydon, tierra).
tipo(rhydon, roca).
tipo(chansey, normal).
tipo(tangela, planta).
tipo(kangaskhan, normal).
tipo(horsea, agua).
tipo(seadra, agua).
tipo(goldeen, agua).
tipo(seaking, agua).
tipo(staryu, agua).
tipo(starmie, agua).
tipo(starmie, psíquico).
tipo(mr_mime, psíquico).
tipo(scyther, bicho).
tipo(scyther, volador).
tipo(jynx, hielo).
tipo(jynx, psíquico).
tipo(electabuzz, eléctrico).
tipo(magmar, fuego).
tipo(pinsir, bicho).
tipo(tauros, normal).
tipo(magikarp, agua).
tipo(gyarados, agua).
tipo(gyarados, volador).
tipo(lapras, agua).
tipo(lapras, hielo).
tipo(ditto, normal).
tipo(eevee, normal).
tipo(vaporeon, agua).
tipo(jolteon, eléctrico).
tipo(flareon, fuego).
tipo(porygon, normal).
tipo(omanyte, roca).
tipo(omanyte, agua).
tipo(omastar, roca).
tipo(omastar, agua).
tipo(kabuto, roca).
tipo(kabuto, agua).
tipo(kabutops, roca).
tipo(kabutops, agua).
tipo(aerodactyl, roca).
tipo(aerodactyl, volador).
tipo(snorlax, normal).
tipo(articuno, hielo).
tipo(articuno, volador).
tipo(zapdos, eléctrico).
tipo(zapdos, volador).
tipo(moltres, fuego).
tipo(moltres, volador).
tipo(dratini, dragón).
tipo(dragonair, dragón).
tipo(dragonite, dragón).
tipo(dragonite, volador).
tipo(mewtwo, psíquico).
tipo(mew, psíquico).


% TABLA DE TIPOS

% Relaciones de Eficacia
eficaz(acero, roca).
eficaz(acero, hielo).
eficaz(agua, fuego).
eficaz(agua, roca).
eficaz(agua, tierra).
eficaz(bicho, planta).
eficaz(bicho, psíquico).
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
eficaz(psíquico, lucha).
eficaz(psíquico, veneno).
eficaz(roca, bicho).
eficaz(roca, fuego).
eficaz(roca, hielo).
eficaz(roca, volador).
eficaz(siniestro, fantasma).
eficaz(siniestro, psíquico).
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
debil(lucha, psíquico).
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
inmune(psiqico, siniestro).
inmune(tierra, eléctrico).
inmune(volador, tierra).
