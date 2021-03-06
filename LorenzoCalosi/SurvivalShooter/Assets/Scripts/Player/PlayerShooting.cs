﻿using UnityEngine;
using UnityEngine.UI;

public class PlayerShooting : MonoBehaviour
{
    public int damagePerShot = 20;
    public float timeBetweenBullets = 0.15f;
	public float timeBetweenGrenades = 1.0f;
	public int startingGrenades = 3;
	public int currentGrenades = 0;
	public float grenadeForce = 5.0f;
    public float range = 100f;
	public Rigidbody grenadePrefab;
	public Text grenadeText;


    float timer;
	float grenadeTimer;
    Ray shootRay = new Ray();
    RaycastHit shootHit;
    int shootableMask;
    ParticleSystem gunParticles;
    LineRenderer gunLine;
    AudioSource gunAudio;
    Light gunLight;
    float effectsDisplayTime = 0.2f;


    void Awake ()
    {
		currentGrenades = startingGrenades;
		grenadeText.text = "Grenades: " + currentGrenades;
        shootableMask = LayerMask.GetMask ("Shootable");
        gunParticles = GetComponent<ParticleSystem> ();
        gunLine = GetComponent <LineRenderer> ();
        gunAudio = GetComponent<AudioSource> ();
        gunLight = GetComponent<Light> ();
    }


    void Update ()
    {
        timer += Time.deltaTime;
		grenadeTimer += Time.deltaTime;

		if(Input.GetButton ("Fire1") && timer >= timeBetweenBullets && Time.timeScale != 0)
        {
            Shoot ();
        }

		if (Input.GetButtonDown ("Fire2") && grenadeTimer >= timeBetweenGrenades && currentGrenades > 0 && Time.timeScale != 0) {
			GrenadeToss ();
		}

        if(timer >= timeBetweenBullets * effectsDisplayTime)
        {
            DisableEffects ();
        }
    }


    public void DisableEffects ()
    {
        gunLine.enabled = false;
        gunLight.enabled = false;
    }


    void Shoot ()
    {
        timer = 0f;

        gunAudio.Play ();

        gunLight.enabled = true;

        gunParticles.Stop ();
        gunParticles.Play ();

        gunLine.enabled = true;
        gunLine.SetPosition (0, transform.position);

        shootRay.origin = transform.position;
        shootRay.direction = transform.forward;

        if(Physics.Raycast (shootRay, out shootHit, range, shootableMask))
        {
            EnemyHealth enemyHealth = shootHit.collider.GetComponent <EnemyHealth> ();
            if(enemyHealth != null)
            {
                enemyHealth.TakeDamage (damagePerShot, shootHit.point);
            }
            gunLine.SetPosition (1, shootHit.point);
        }
        else
        {
            gunLine.SetPosition (1, shootRay.origin + shootRay.direction * range);
        }
    }

	void GrenadeToss()
	{
		grenadeTimer = 0f;
		currentGrenades--;
		grenadeText.text = "Grenades: " + currentGrenades;
		Rigidbody grenade = Instantiate (grenadePrefab, transform.position, transform.rotation);
		Vector3 direction = transform.TransformDirection (new Vector3(0,1,1) * grenadeForce);
		grenade.AddForce (direction, ForceMode.Impulse);
	}
}
