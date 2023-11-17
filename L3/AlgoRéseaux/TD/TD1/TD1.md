# Exercice 1
Trame : Data = None
Events : 
Data.req(d)
recvd(P)

sender(): 
    t = trame()
    while true: // Ils travaillent en continu
        wait(Data.req(d))
        t.data=d
        send(P)

receiver():
    while true:
        wait(recvd(P))
        data.imd(P.data)


# Exercice 2
Trame : Data = None
Events:  Data.req(d) recvd(P)

sender():
    t = trame()
    canSend = true
    while true:
        wait(Data.req(d),recvd(P))
        if event == Data.req(d):
            if canSend :
                t.data=d
                send(t)
                canSend=false
        if event == recvd(P):
            canSend = true
        
receiver():
    t=trame()
    while true:
        wait(recvd(P))
        Data.imd(P.data)
        send(t)


# Exercice 3
Trame:
Data = None
seq = None

Events:
Data.req(d) recvd(P) timeout

sender():
    t = trame()
    PTAE = 0, canSend = true
    while true:
    wait()
    if(data.req(d)and canSend)
        t.data=dt.seq = PTAE
        send(t)
        start_timer()
        canSend = false
    if(recvd(p)):
        stop_timer()
        canSend = true
        PTAE = PTAE + 1 mod 2
    if timeout:
        send(t)
        start_timer()

receiver():
    TA = 0
    t = trame()
    while true
        wait(recvd(P))
        if(P.seq==TA):
            Data.imd(P.data)
            TA = TA+1 mod 2
        send(t)


# Exercice 5
Frame:
Data = None
Seq = None

Events:
Data.req(d)
recvd(P)
timeout

sender():
    f = frame()
    list_f=[None] * N
    ptae=0
    ptna=0
    canSend=true
    while true:
        wait()
        if event == Dara.req(d) and canSend:
            f.data=d
            f.seq=ptae
            list_f[ptae] = f.copy()
            send(f)
            start_timer()
            ptae++
            if(ptae-ptna >= N)
                canSend=true
        if event == recvd(P) and Pseq == ptae+1:
            stop_timer()
            canSend=true
            ptna = ptna + 1 % N+1
        if event == timeout
            for i in (ptna,ptne):
                send(list_f[i])
                start timer()

receiver():
    f = frame()
    ta=0
    while true:
        wait(recv(P))
        if p.seq==ta:
            Data.imd(p.data)
            ta=ta+1 mod N+1
            f.seq(ta)
            send(f)


# Exo 6

Receiver():
    data=[None]*N
    ta=0
    f=Frame()
    while true:
    wait(recvd(P))
        if p.seq==ta:
            Data.imd(P.data)
            ta=ta+1 mod N+1
            f.type=ACK
            while data[ta].type != ACK
                Data.imd(data[ta])
                data[ta] = None
                ta=ta+1 mod N+1
        if p.seq>ta:
            data[p.seq] = p.data
            f.type=NACK
        f.seq=ta
        send(f)
        f.type=ACK


