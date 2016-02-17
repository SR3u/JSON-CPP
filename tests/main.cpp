//
//  main.cpp
//  JSON
//
//  Created by Sergey Rump on 23.09.2015.
//  Copyright (c) 2015 Motorola Solutions. All rights reserved.
//

#include <iostream>
#include "json.h"
void test(void)
{
    std::string jsonStr="{\"arr\":[1,2,3],\"key\":\"value\",\"obj\":{\"k\":\"v\"},\"bool\":true}";
    std::JSON json(jsonStr);
    std::cout <<json.toString()<<"\n";
    json.parse(json.toString());
    std::cout <<json.toString()<<"\n";
}
void test_0()
{
    std::string jsonStr="{\"arr\":[1,2,3],\"key\":\"value\",\"obj\":{\"k\":\"v\"},\"bool\":true}";
    std::JSON json(jsonStr);
    std::cout <<json.toString()<<"\n";
    std::JSON obj=json.getJSON("obj");
    obj.set("kk", "vv");
    json.set("obj",obj);
    std::string tmp=json.toString();
    std::JSON temp(json.toString());
    std::cout <<temp.toString()<<"\n";
    std::JSON arr=json.getJSON("arr");
    arr.set(4, 44);
    std::cout <<arr.toString()<<"\n";
    json.set("arr", arr);
    std::cout <<json.toString()<<"\n";
    std::cout<<arr.getString(0)<<"\n";
    std::cout<<arr.getString(1)<<"\n";
    std::cout<<arr.getString(2)<<"\n";
}
int main(int argc, const char * argv[])
{
    //while (true){test();}
    std::string jsonStr="[0,1,\"string mf\",3]";
    std::JSON jsonArray(jsonStr);
    std::cout<<jsonArray.getString(2)<<"\n";
    return 0;
    std::string str="{\"framework\":\"apd-framework-8.6.1\",\"title\":\"Keynote Hjälp\",\"build_id\":\"2014.08.23-07:35:24\",\"icon\":\"..\\/GlobalArt\\/AppIconDefault_KeynoteP4.png\",\"sections\":{\"tan72234385\":{\"name\":\"Komma igång med Keynote\",\"children\":[\"tan79a8f6388\",\"tan72232b56\",\"tanae4979928\",\"tan81f1db118\",\"tan2fd9e39d8\"]},\"tanb5e9b09a\":{\"name\":\"Visa en presentation\",\"children\":[\"tan72233051\",\"tan9d3a4bb59\",\"tanfaf45e5a4\",\"tan76d396b3d\",\"tana4da2681\",\"tand1a4ee7c\",\"tan1cb6ca7a3\",\"tan9e9970a4\",\"tan30608d10e\"]},\"tan54b716c0e\":{\"name\":\"Diabildsövergångar\",\"children\":[\"tanff5ae749e\",\"tan2bdb4d136\"]},\"tanb5e9ae2e\":{\"name\":\"Lägga till bilder, former och medier\",\"children\":[\"tan72232820\",\"tan77aea6844\",\"tanbbe3614e0\",\"tan63d61519a\",\"tan092bc56a7\",\"tanac67fc782\",\"tanc0606ae81\",\"tan822a41db2\",\"tan14694329b\",\"tan003ee8980\",\"tande32a1b86\"]},\"tanb5e9b153\":{\"name\":\"Dela och skriva ut presentationer\",\"children\":[\"tan79be8e93\",\"tan5fc7516cf\",\"tan5394fbf0f\",\"tan343d4b90d\",\"tand166234d8\",\"tand51dba2c\"]},\"tanfeff8d5d6\":{\"name\":\"Diagram\",\"children\":[\"tan1a8924264\",\"tan2769aa2ba\",\"tand1d449c87\",\"tance6106262\",\"tan9e7c35220\",\"tanfdc87155f\",\"tan9442733c8\"]},\"tan6b7a06c82\":{\"name\":\"Formler och funktioner\",\"children\":[\"tanfb0588a84\",\"tane76a3f8cb\",\"tanf0b5a049a\",\"tan0f4aefdb6\"]},\"tanb0d5359e7\":{\"name\":\"Lägga till tabeller och diagram\",\"children\":[\"tan271aff3f5\",\"tan6b7a06c82\",\"tanfeff8d5d6\"]},\"tanb5e9afd1\":{\"name\":\"Animera diabilder\",\"children\":[\"tan54b716c0e\",\"tan72234bb6\"]},\"tanf0b5a049a\":{\"name\":\"Strängoperatorer och jokertecken\",\"children\":[\"tan7132f4c15\",\"tan3c62ca531\"]},\"tan75436000b\":{\"name\":\"Kortkommandon\",\"children\":[\"tanfde4a3e6d\",\"tan951def1c9\"]},\"tanb88fac38a\":{\"name\":\"Lägga till och ordna diabilder\",\"children\":[\"tan7223571d\",\"tan1528cd3c2\",\"tan37aa60871\",\"tan98841ef85\",\"tan9cbb7c9fe\",\"tan7a2b69972\",\"tan40488a58d\",\"tanb343cb739\"]},\"tanbb7600291\":{\"name\":\"Markera, redigera och formatera text\",\"children\":[\"tan30ea6907b\",\"tan94ed1b3ac\",\"tanfce072687\",\"tanae142dbac\",\"tan423db6ff6\",\"tan3736c1f8d\",\"tan3bcf5a795\",\"tan7c20d79b0\",\"tan5bbe45dce\",\"tan9e2c0593f\",\"tan487a67d45\",\"tan5a62671dc\",\"tan076c382d1\",\"tanb0b2be205\",\"tan30a88784c\",\"tan4333e1668\",\"tan27594558f\"]},\"tan271aff3f5\":{\"name\":\"Tabeller\",\"children\":[\"tan24e79323e\",\"tana61f16820\",\"tanceb11031e\",\"tanc56d2f788\",\"tana0c3cad0e\",\"tanf18a5b050\",\"tan0f2fb8c3a\",\"tan7919debab\",\"tandf8adc290\",\"tan6c7b4595a\",\"tan6cbe92ac3\",\"tan916675fa6\",\"tanfcb63a8e0\",\"tan373ab4341\"]},\"tan599b98237\":{\"name\":\"Hantera presentationer\",\"children\":[\"tanf51f6f6d9\",\"tan9de5c6721\",\"tan982da7313\",\"tan3412af927\",\"tan8364d71a5\",\"tan5e92a9af0\"]}},\"birdseed_version\":3,\"toc\":[\"tan72234385\",\"tanb88fac38a\",\"tanb5e9ae2e\",\"tanbb7600291\",\"tanb0d5359e7\",\"tanb5e9afd1\",\"tanb5e9b09a\",\"tan599b98237\",\"tanb5e9b153\",\"tan75436000b\"],\"locale\":\"sv\",\"version\":\"6.5\",\"enable_tracking\":false,\"source_schema\":\"apd-schema\",\"platform\":\"mac\",\"design\":\"default\",\"build_date\":\"2014.08.23-07:35:52\",\"landing\":\"tan72790c91\",\"product\":\"keynote\",\"urls\":{},\"copyright\":\"\",\"topics\":{\"tan1cb6ca7a3\":{\"name\":\"Öva på en presentation\",\"href\":\"tan1cb6ca7a3.html\",\"unavailable\":true},\"tan37aa60871\":{\"name\":\"Ändra ordning på diabilderna\",\"href\":\"tan37aa60871.html\",\"unavailable\":true},\"tan916675fa6\":{\"name\":\"Ändra storlek på, flytta och låsa en tabell\",\"href\":\"tan916675fa6.html\",\"unavailable\":true},\"tanb343cb739\":{\"name\":\"Lägga till anpassade teman\",\"href\":\"tanb343cb739.html\",\"unavailable\":true},\"tanae142dbac\":{\"name\":\"Lägga till avstånd mellan ord och stycken\",\"href\":\"tanae142dbac.html\",\"unavailable\":true},\"tan5bbe45dce\":{\"name\":\"Kontrollera stavning\",\"href\":\"tan5bbe45dce.html\",\"unavailable\":true},\"tan0f2fb8c3a\":{\"name\":\"Lägga till en kommentar för en cell\",\"href\":\"tan0f2fb8c3a.html\",\"unavailable\":true},\"tan2fd9e39d8\":{\"name\":\"Ångra och göra om ändringar\",\"href\":\"tan2fd9e39d8.html\",\"unavailable\":true},\"tan76d396b3d\":{\"name\":\"Ställa in uppspelningsalternativ för presentationen\",\"href\":\"tan76d396b3d.html\",\"unavailable\":true},\"tan72232b56\":{\"name\":\"Skapa och öppna en presentation\",\"href\":\"tan72232b56.html\",\"unavailable\":true},\"tance6106262\":{\"name\":\"Justera markeringar och etiketter för ett diagram\",\"href\":\"tance6106262.html\",\"unavailable\":true},\"tan30ea6907b\":{\"name\":\"Lägga till text\",\"href\":\"tan30ea6907b.html\",\"unavailable\":true},\"tan2e4a77fdd\":{\"name\":\"Spara ett diagram som en ny stil\",\"href\":\"tan2e4a77fdd.html\"},\"tand51dba2c\":{\"name\":\"Dela filer via en fjärrserver\",\"href\":\"tand51dba2c.html\"},\"tan43ce89278\":{\"categories\":[\"glossary\"],\"name\":\"Formatgranskaren\",\"href\":\"tan43ce89278.html\",\"unavailable\":true},\"tand1a4ee7c\":{\"name\":\"Använda presentationsanteckningar\",\"href\":\"tand1a4ee7c.html\",\"unavailable\":true},\"tan30a88784c\":{\"name\":\"Formatera skiljetecken\",\"href\":\"tan30a88784c.html\",\"unavailable\":true},\"tan487a67d45\":{\"name\":\"Kopiera och klistra in text\",\"href\":\"tan487a67d45.html\",\"unavailable\":true},\"tan7132f4c15\":{\"name\":\"Sätt att använda strängoperatorn och jokertecken\",\"href\":\"tan7132f4c15.html\",\"unavailable\":true},\"tan9442733c8\":{\"name\":\"Spara och ordna diagramstilar\",\"href\":\"tan9442733c8.html\",\"unavailable\":true},\"tan72234bb6\":{\"name\":\"Animera objekt\",\"href\":\"tan72234bb6.html\",\"unavailable\":true},\"tanf558aa032\":{\"categories\":[\"glossary\"],\"name\":\"markera hela rader eller kolumner\",\"href\":\"tanf558aa032.html\",\"unavailable\":true},\"tan63d61519a\":{\"name\":\"Lägga till video och ljud\",\"href\":\"tan63d61519a.html\",\"unavailable\":true},\"tanf18a5b050\":{\"name\":\"Slå ihop och splittra celler\",\"href\":\"tanf18a5b050.html\",\"unavailable\":true},\"tanfde4a3e6d\":{\"name\":\"Kortkommandon\",\"href\":\"tanfde4a3e6d.html\",\"unavailable\":true},\"tan9cbb7c9fe\":{\"name\":\"Hoppa över en diabild\",\"href\":\"tan9cbb7c9fe.html\",\"unavailable\":true},\"tan3bf67cfee\":{\"categories\":[\"glossary\"],\"name\":\"tema\",\"href\":\"tan3bf67cfee.html\",\"unavailable\":true},\"tanfdc87155f\":{\"name\":\"Ändra utseendet på ett diagram\",\"href\":\"tanfdc87155f.html\",\"unavailable\":true},\"tane8daa7afa\":{\"categories\":[\"glossary\"],\"name\":\"dataserier\",\"href\":\"tane8daa7afa.html\",\"unavailable\":true},\"tan2bdb4d136\":{\"name\":\"Lägga till en Magisk flytt-övergång\",\"href\":\"tan2bdb4d136.html\",\"unavailable\":true},\"tan2769aa2ba\":{\"name\":\"Flytta, ändra storlek på eller rotera ett diagram\",\"href\":\"tan2769aa2ba.html\",\"unavailable\":true},\"tana61f16820\":{\"name\":\"Lägga till rader och kolumner\",\"href\":\"tana61f16820.html\",\"unavailable\":true},\"tan9de5c6721\":{\"name\":\"Spara en presentation i ett annat format\",\"href\":\"tan9de5c6721.html\"},\"tanceb11031e\":{\"name\":\"Lägga till innehåll i tabellceller\",\"href\":\"tanceb11031e.html\",\"unavailable\":true},\"tan9e2c0593f\":{\"name\":\"Söka och ersätta text\",\"href\":\"tan9e2c0593f.html\",\"unavailable\":true},\"tan30608d10e\":{\"name\":\"Markeringar på diabilder under presentationer\",\"href\":\"tan30608d10e.html\",\"unavailable\":true},\"tan3412af927\":{\"name\":\"Lägga till ett lösenord för en presentation\",\"href\":\"tan3412af927.html\",\"unavailable\":true},\"tan27594558f\":{\"name\":\"Formatera kinesisk, japansk eller koreansk text\",\"href\":\"tan27594558f.html\",\"unavailable\":true},\"tan79be8e93\":{\"name\":\"Använda iCloud med Keynote\",\"href\":\"tan79be8e93.html\",\"unavailable\":true},\"tan7919debab\":{\"name\":\"Lägga till villkorad markering i celler\",\"href\":\"tan7919debab.html\",\"unavailable\":true},\"tan81f1db118\":{\"name\":\"Anpassa verktygsfältet\",\"href\":\"tan81f1db118.html\",\"unavailable\":true},\"tan09680d9f0\":{\"categories\":[\"glossary\"],\"name\":\"markera celler\",\"href\":\"tan09680d9f0.html\",\"unavailable\":true},\"tan003ee8980\":{\"name\":\"Placera objekt i lager och gruppera och låsa objekt\",\"href\":\"tan003ee8980.html\",\"unavailable\":true},\"tanfa67b124a\":{\"categories\":[\"glossary\"],\"name\":\"AirDrop\",\"href\":\"tanfa67b124a.html\",\"unavailable\":true},\"tan94ed1b3ac\":{\"name\":\"Skapa listor med punkter eller numrering\",\"href\":\"tan94ed1b3ac.html\",\"unavailable\":true},\"tanfaf45e5a4\":{\"name\":\"Spela in en självspelande berättarröst\",\"href\":\"tanfaf45e5a4.html\",\"unavailable\":true},\"tan5fc7516cf\":{\"name\":\"Dela och redigera en presentation med andra\",\"href\":\"tan5fc7516cf.html\",\"unavailable\":true},\"tan076c382d1\":{\"name\":\"Lägga till kommentarer och markera text\",\"href\":\"tan076c382d1.html\",\"unavailable\":true},\"tan4d8f89c38\":{\"categories\":[\"glossary\"],\"name\":\"webbläsare som stöds för delning\",\"href\":\"tan4d8f89c38.html\",\"unavailable\":true},\"tan7a2b69972\":{\"name\":\"Lägga till och redigera sidmallar\",\"href\":\"tan7a2b69972.html\",\"unavailable\":true},\"tan98841ef85\":{\"name\":\"Gruppera diabilder\",\"href\":\"tan98841ef85.html\",\"unavailable\":true},\"tandf8adc290\":{\"name\":\"Ändra utseendet på en tabell\",\"href\":\"tandf8adc290.html\",\"unavailable\":true},\"tand1db76f4a\":{\"categories\":[\"glossary\"],\"name\":\"Funktionsbläddrare\",\"href\":\"tand1db76f4a.html\",\"unavailable\":true},\"tanae4979928\":{\"name\":\"Olika sätt att visa diabilderna\",\"href\":\"tanae4979928.html\",\"unavailable\":true},\"tan1528cd3c2\":{\"name\":\"Visa och gömma diabildsnummer\",\"href\":\"tan1528cd3c2.html\",\"unavailable\":true},\"tana0c3cad0e\":{\"name\":\"Skapa ett anpassat cellformat\",\"href\":\"tana0c3cad0e.html\",\"unavailable\":true},\"tan1853ba945\":{\"categories\":[\"glossary\"],\"name\":\"verktygsfält\",\"href\":\"tan1853ba945.html\",\"unavailable\":true},\"tane76a3f8cb\":{\"name\":\"Olika typer av argument och värden\",\"href\":\"tane76a3f8cb.html\",\"unavailable\":true},\"tan40488a58d\":{\"name\":\"Ändra en presentations tema\",\"href\":\"tan40488a58d.html\",\"unavailable\":true},\"tan3c62ca531\":{\"name\":\"Funktioner som godtar villkor och jokertecken som argument\",\"href\":\"tan3c62ca531.html\",\"unavailable\":true},\"tanff5ae749e\":{\"name\":\"Lägga till övergångar\",\"href\":\"tanff5ae749e.html\",\"unavailable\":true},\"tand1d449c87\":{\"name\":\"Ändra diagramdata\",\"href\":\"tand1d449c87.html\",\"unavailable\":true},\"tan5e92a9af0\":{\"name\":\"Radera en presentation\",\"href\":\"tan5e92a9af0.html\",\"unavailable\":true},\"tan6c7b4595a\":{\"name\":\"Ändra utseendet på tabelltext\",\"href\":\"tan6c7b4595a.html\",\"unavailable\":true},\"tanc56d2f788\":{\"name\":\"Formatera tabellceller\",\"href\":\"tanc56d2f788.html\",\"unavailable\":true},\"tanf51f6f6d9\":{\"name\":\"Spara och byta namn på en presentation\",\"href\":\"tanf51f6f6d9.html\",\"unavailable\":true},\"tan72232820\":{\"name\":\"Objekt i översikt\",\"href\":\"tan72232820.html\",\"unavailable\":true},\"tan092bc56a7\":{\"name\":\"Ändra ett objekts utseende\",\"href\":\"tan092bc56a7.html\",\"unavailable\":true},\"tan8efc47c2e\":{\"categories\":[\"glossary\"],\"name\":\"iCloud\",\"href\":\"tan8efc47c2e.html\",\"unavailable\":true},\"tan8364d71a5\":{\"name\":\"Flytta en presentation till eller från iCloud\",\"href\":\"tan8364d71a5.html\",\"unavailable\":true},\"tan72233051\":{\"name\":\"Spela upp en presentation\",\"href\":\"tan72233051.html\",\"unavailable\":true},\"tanfce072687\":{\"name\":\"Ändra utseendet på text\",\"href\":\"tanfce072687.html\",\"unavailable\":true},\"tan423db6ff6\":{\"name\":\"Kantjustera text\",\"href\":\"tan423db6ff6.html\",\"unavailable\":true},\"tan951def1c9\":{\"name\":\"Kortkommandosymboler\",\"href\":\"tan951def1c9.html\"},\"tan822a41db2\":{\"name\":\"Göra linjalinställningar\",\"href\":\"tan822a41db2.html\",\"unavailable\":true},\"tan636f2d4e7\":{\"categories\":[\"glossary\"],\"name\":\"Apple-ID\",\"href\":\"tan636f2d4e7.html\",\"unavailable\":true},\"tande32a1b86\":{\"name\":\"Lägga till en länk\",\"href\":\"tande32a1b86.html\",\"unavailable\":true},\"tand166234d8\":{\"name\":\"Överföra filer via iTunes\",\"href\":\"tand166234d8.html\",\"unavailable\":true},\"tana4da2681\":{\"name\":\"Visa en presentation på en separat bildskärm\",\"href\":\"tana4da2681.html\",\"unavailable\":true},\"tan14694329b\":{\"name\":\"Justera och placera objekt\",\"href\":\"tan14694329b.html\",\"unavailable\":true},\"tan5394fbf0f\":{\"name\":\"Skicka en kopia av en presentation\",\"href\":\"tan5394fbf0f.html\"},\"tanb0b2be205\":{\"name\":\"Lägg till färg i en textruta eller en ram runt den\",\"href\":\"tanb0b2be205.html\",\"unavailable\":true},\"tand7af1c122\":{\"categories\":[\"glossary\"],\"name\":\"lås upp en tabell, ett diagram, en form eller en textruta\",\"href\":\"tand7af1c122.html\",\"unavailable\":true},\"tanfcb63a8e0\":{\"name\":\"Sortera data i en kolumn\",\"href\":\"tanfcb63a8e0.html\",\"unavailable\":true},\"tan72790c91\":{\"name\":\"Keynote Hjälp\",\"href\":\"tan72790c91.html\",\"categories\":[\"landing\"]},\"tan3bcf5a795\":{\"name\":\"Göra tecken upphöjda eller nedsänkta\",\"href\":\"tan3bcf5a795.html\",\"unavailable\":true},\"tanac67fc782\":{\"name\":\"Skapa objektstilar\",\"href\":\"tanac67fc782.html\",\"unavailable\":true},\"tanbbe3614e0\":{\"name\":\"Lägga till och redigera former\",\"href\":\"tanbbe3614e0.html\",\"unavailable\":true},\"tan1a8924264\":{\"name\":\"Lägga till eller radera ett diagram\",\"href\":\"tan1a8924264.html\",\"unavailable\":true},\"tan343d4b90d\":{\"name\":\"Skriva ut en presentation\",\"href\":\"tan343d4b90d.html\",\"unavailable\":true},\"tan77aea6844\":{\"name\":\"Lägga till och redigera bilder\",\"href\":\"tan77aea6844.html\",\"unavailable\":true},\"tan0f4aefdb6\":{\"name\":\"Lägga en ekvation med MathType\",\"href\":\"tan0f4aefdb6.html\",\"unavailable\":true},\"tan79a8f6388\":{\"name\":\"En snabbtitt på Keynote\",\"href\":\"tan79a8f6388.html\",\"unavailable\":true},\"tan7223571d\":{\"name\":\"Lägga till diabilder\",\"href\":\"tan7223571d.html\",\"unavailable\":true},\"tanfb0588a84\":{\"name\":\"Beräkningar\",\"href\":\"tanfb0588a84.html\",\"unavailable\":true},\"tan4cccfb9c5\":{\"categories\":[\"glossary\"],\"name\":\"iCloud-konto\",\"href\":\"tan4cccfb9c5.html\",\"unavailable\":true},\"tan5a62671dc\":{\"name\":\"Ersätta text automatiskt\",\"href\":\"tan5a62671dc.html\",\"unavailable\":true},\"tan7c20d79b0\":{\"name\":\"Lägga till ligaturer\",\"href\":\"tan7c20d79b0.html\",\"unavailable\":true},\"tan6cbe92ac3\":{\"name\":\"Spara en tabell som en ny stil\",\"href\":\"tan6cbe92ac3.html\",\"unavailable\":true},\"tan43d41a7b7\":{\"categories\":[\"glossary\"],\"name\":\"nyckelring\",\"href\":\"tan43d41a7b7.html\",\"unavailable\":true},\"taned1349593\":{\"categories\":[\"glossary\"],\"name\":\"tagg\",\"href\":\"taned1349593.html\",\"unavailable\":true},\"tan9e7c35220\":{\"name\":\"Ändra diagramtypen\",\"href\":\"tan9e7c35220.html\",\"unavailable\":true},\"tan4333e1668\":{\"name\":\"Använda dubbelriktad text\",\"href\":\"tan4333e1668.html\",\"unavailable\":true},\"tan4e89e275c\":{\"name\":\"Dela en presentation med andra\",\"href\":\"tan4e89e275c.html\"},\"tan3736c1f8d\":{\"name\":\"Använda styckestilar\",\"href\":\"tan3736c1f8d.html\",\"unavailable\":true},\"tan373ab4341\":{\"name\":\"Formatera tabeller för dubbelriktad text\",\"href\":\"tan373ab4341.html\",\"unavailable\":true},\"tan24e79323e\":{\"name\":\"Lägga till och radera tabeller\",\"href\":\"tan24e79323e.html\",\"unavailable\":true},\"tan9e9970a4\":{\"name\":\"Använda Keynote Remote\",\"href\":\"tan9e9970a4.html\",\"unavailable\":true},\"tan982da7313\":{\"name\":\"Låsa en presentation\",\"href\":\"tan982da7313.html\",\"unavailable\":true},\"tanc0606ae81\":{\"name\":\"Ändra storlek på, rotera och vända ett objekt\",\"href\":\"tanc0606ae81.html\",\"unavailable\":true},\"tan9d3a4bb59\":{\"name\":\"Ändra till en presentation till att använda länkar eller vara självspelande\",\"href\":\"tan9d3a4bb59.html\",\"unavailable\":true}},\"copyright_text\":\"\",\"css\":\"\"}";
    std::JSON json(str);
    std::cout<<json.toString()<<'\n';
    return 0;
}
