DROP SCHEMA IF EXISTS bibliotheek;
CREATE SCHEMA IF NOT EXISTS bibliotheek;

DROP TABLE IF EXISTS bibliotheek.magazine;
CREATE TABLE IF NOT EXISTS bibliotheek.magazine(
	magazine_id INT auto_increment,
	naam varchar(30) NOT NULL,
	uitgeverij varchar(30) NOT NULL,
    thema varchar(50) NOT NULL,
    beschrijving varchar(200) NOT NULL,
	datum date NOT NULL,
    foto varchar(200) NOT NULL,
	CONSTRAINT PK_Magazine
	PRIMARY KEY(magazine_id)
);

DROP TABLE IF EXISTS bibliotheek.robot;
CREATE TABLE IF NOT EXISTS bibliotheek.robot(
	robot_id INT auto_increment PRIMARY KEY,
    FkMagazine INT NOT NULL,
    CONSTRAINT fk_connection
    FOREIGN KEY (FkMagazine)
    REFERENCES magazine(magazine_id)
);
SELECT m.magazine_id FROM bibliotheek.magazine m WHERE m.naam = "Flair" AND m.datum = "2023-03-21";
INSERT INTO bibliotheek.magazine (naam, uitgeverij, thema, beschrijving, datum, foto) VALUES ("naam", "uitgeverij", "thema", "beschrijving", "datum", "foto");
INSERT INTO bibliotheek.magazine (naam, uitgeverij, thema, beschrijving, datum, foto) VALUES 
("Libelle", "Roularta", "Vrouwenblad", "Een weekblad van inspiratie voor vrouwen die graag zorgen voor zichzelf en hun geliefden.", "2023-03-20", "https://makr.roularta.be/covers/ARCHIEF/2023/12/HF/COVER/cover_300_0.jpg"),
("Dag Allemaal", "DPG-media", "Weekblad", "Leef elke week mee met het wel en wee van bekend Vlaanderen.", "2023-03-21", "https://www.dagallemaal.be/wp-content/uploads/2023/03/171_GPV1QU_20230321_DAZXT_00_coverFCKSTRIP-scaled.jpg"),
("Flair","Roularta", "Vrouwenblad","Flair is de mentor voor jonge vrouwen op zoek naar hun eigen identiteit.","2023-03-21","https://makr.roularta.be/covers/ARCHIEF/2023/12/FM/COVER/cover_0_0.jpg"),
("Feeling", "Roularta","Vrouwenblad", "Feeling brengt je elke dag de laatste updates op gebied van mode, beauty, lifestyle, cultuur en gezondheid.","2023-03-21","https://makr.roularta.be/covers/ARCHIEF/2023/04/AV/COVER/cover_0_0.jpg"),
("Primo","De Persgroep", "weekblad", "Primo is het gezelligste weekblad van Vlaanderen met een fijne mix van nostalgie en actualiteit.","2023-03-25","https://www.showbizzsite.be/sites/default/files/styles/news_page_details/public/primo_15.jpeg?h=6ef98373"),
("Sport/Voetbalmagazine","Roularta","Sportmagazine","Sport/Voetbalmagazine is er voor de voetballiefhebber die op zoek is naar achtergronden, interviews en verbredende opinies. Dus voor de fans die leven voor voetbal","2023-03-30","https://ikkoopbelgisch.be/media/cache/standard/rc/Ty2rUrAk/uploads/media/5ec2ffad0f639/7061-extra3.jpg");
SET SQL_SAFE_UPDATES = 0;
DELETE FROM bibliotheek.magazine WHERE magazine.naam = "Libelle" AND magazine.datum = "2023-03-20" AND magazine.magazine_id IS NOT NULL;

UPDATE bibliotheek.magazine
SET naam = "Test"
WHERE magazine.naam = "Libelle";
