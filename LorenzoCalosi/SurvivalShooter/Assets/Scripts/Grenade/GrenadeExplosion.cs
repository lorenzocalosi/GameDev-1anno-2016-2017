using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GrenadeExplosion : MonoBehaviour {

	public float explosionRadius = 10.0f;
	public int explosionDamage = 50;

	void OnCollisionEnter(Collision other) {
		Debug.Log ("Collided with " + other.gameObject.name);
		if (other.gameObject.tag != "Player" ) {
			Collider[] hitArray = Physics.OverlapSphere(transform.position, explosionRadius, LayerMask.GetMask("Shootable"));
			for (int i = 0; i < hitArray.Length; i++) {
				if (hitArray [i].GetComponent<EnemyHealth> () != null) {
					hitArray [i].GetComponent<EnemyHealth> ().TakeDamage (explosionDamage, hitArray[i].GetComponent<EnemyHealth>().transform.position);
				}
			}
			Destroy (gameObject);
		}
	}
}
