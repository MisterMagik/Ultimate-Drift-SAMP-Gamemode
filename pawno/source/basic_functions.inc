#if !defined __BASIC_FUNCTIONS__
#define __BASIC_FUNCTIONS__

stock GetPlayerNick(playerid)
{
    tmpStr[0] = EOS;
    GetPlayerName(playerid, tmpStr, sizeof(tmpStr));
    return tmpStr;
}

stock isCar(vehicleid)
{
    switch(vehcileid)
    {
        case 400 .. 402:
        {
            return true;
        }

        case 404 .. 405:
        {
            return true;
        }

        case 409 .. 412:
        {
            return true;
        }

        case 415:
        {
            return true;
        }

        case 418 .. 422:
        {
            return true;
        }

        case 424:
        {
            return true;
        }

        case 426:
        {
            return true;
        }
        
        case 429:
        {
            return true;
        }

        case 434:
        {
            return true;
        }

        case 436:
        {
            return true;
        }

        case 438 .. 439:
        {
            return true;
        }

        case 442:
        {
            return true;
        }

        case 445:
        {
            return true;
        }

        case 451:
        {
            return true;
        }

        case 458:
        {
            return true;
        }

        case 466 .. 467:
        {
            return true;
        }

        case 470:
        {
            return true;
        }

        case 474 .. 475:
        {
            return true;
        }

        case 477 .. 480:
        {
            return true;
        }

        case 483:
        {
            return true;
        }

        case 489 .. 492:
        {
            return true;
        }

        case 494 .. 496:
        {
            return true;
        }

        case 500:
        {
            return true;
        }

        case 502 .. 507:
        {
            return true;
        }

        case 516 .. 518:
        {
            return true;
        }

        case 526 .. 527:
        {
            return true;
        }

        case 529:
        {
            return true;
        }

        case 533 .. 536:
        {
            return true;
        }

        case 540 .. 543:
        {
            return true;
        }

        case 545 .. 547:
        {
            return true;
        }

        case 549 .. 551:
        {
            return true;
        }

        case 554 .. 555:
        {
            return true;
        }

        case 558 .. 562:
        {
            return true;
        }

        case 565 .. 568:
        {
            return true;
        }

        case 575 .. 576:
        {
            return true;
        }

        case 579 .. 580:
        {
            return true;
        }

        case 585:
        {
            return true;
        }

        case 587:
        {
            return true;
        }

        case 589:
        {
            return true;
        }

        case 596 .. 600:
        {
            return true;
        }

        case 602 .. 605:
        {
            return true;
        }


        default:
        {
            return false;
        }
    }
}

stock isTruck(vehicleid)
{
    switch(vehicleid)
    {
        case 403:
        {
            return true;
        }

        case 514 .. 515:
        {
            return true;
        }

        default:
        {
            return false;
        }
    }
}

stock isBike(vehicleid)
{
    switch(vehicleid)
    {
        case 448:
        {
            return true;
        }

        case 461 .. 463:
        {
            return true;
        }

        case 468:
        {
            return true;
        }

        case 471:
        {
            return true;
        }

        case 521 .. 523:
        {
            return true;
        }

        case 581:
        {
            return true;
        }

        case 586:
        {
            return true;
        }


        default:
        {
            return false;
        }
    }
}
#endif